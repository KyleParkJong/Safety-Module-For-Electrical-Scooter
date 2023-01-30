import _thread
import socket
from playsound import playsound
import time

end = 0
print("Server initiating")


def threaded(client_socket, addr):
    print('Connected by: ', addr[0], ':', addr[1])

    while True:
        try:
            data = client_socket.recv(1024)
            if not data:
                print('Disconnected by ' + addr[0], ':', addr[1])
                break

            print('Received from ' + addr[0], ':', addr[1], data.decode())

            client_socket.send(data)
            
            if data.decode() == 'bump':
                playsound('bump.mp3')
            elif data.decode() == 'child':
                playsound('child.mp3')
            elif data.decode() == 'stop':
                playsound('stop.mp3')
          
        except:
            continue      
        # except ConnectionResetError as e:
        #     print("Disconnected by", addr[0], ':', addr[1])
        #     print(f"e: {e}")

ip = '192.168.137.1'   # same with Client (IPv4 addr.)
port = 9999

# 소켓 초기화
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 소켓 에러처리
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

server_socket.bind((ip, port))

server_socket.listen()

print('Server start')

while True:
    if end == 1:
        break
    print("wait")
    cs, addr = server_socket.accept()
    _thread.start_new_thread(threaded, (cs, addr))
    