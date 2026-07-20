import socket

# 服务端地址
SERVER_HOST = "127.0.0.1"
SERVER_PORT = 8888

# 创建客户端套接字
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 连接本地服务端
client_socket.connect((SERVER_HOST, SERVER_PORT))
print("成功连接TCP服务端")

try:
    while True:
        # 控制台输入消息
        send_msg = input("请输入要发送给服务端的消息(quit退出)：")
        if send_msg.lower() == "quit":
            break
        # 发送字符串（编码为bytes）
        client_socket.sendall(send_msg.encode("utf-8"))
        # 接收服务端返回数据
        recv_data = client_socket.recv(1024)
        print("服务端回复：", recv_data.decode("utf-8"))
finally:
    # 关闭套接字
    client_socket.close()
    print("客户端已断开连接")