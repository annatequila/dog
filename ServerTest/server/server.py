import socket

# 1. 创建TCP套接字 SOCK_STREAM
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 端口复用，避免重启时报端口被占用
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# 绑定地址：0.0.0.0 接收本机所有客户端连接，端口 8888
HOST = "0.0.0.0"
PORT = 8888
server_socket.bind((HOST, PORT))

# 开启监听，最大挂起连接数 5
server_socket.listen(5)
print(f"TCP服务端启动成功，监听 {HOST}:{PORT}，等待客户端连接...")

while True:
    # 阻塞等待客户端接入
    client_conn, client_addr = server_socket.accept()
    print(f"新客户端接入：{client_addr}")

    # 循环收发数据
    with client_conn:
        while True:
            # 接收客户端数据，缓冲区1024字节
            recv_data = client_conn.recv(1024)
            if not recv_data:  # 客户端关闭连接，recv返回空字节
                print(f"客户端 {client_addr} 断开连接")
                break
            # 字节转字符串
            msg = recv_data.decode("utf-8")
            print(f"收到客户端消息：{msg}")

            # 回显数据给客户端（echo回声服务）
            resp = f"服务端已收到：{msg}"
            client_conn.sendall(resp.encode("utf-8"))