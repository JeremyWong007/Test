#!/bin/bash

# 定义要传输的文件和目标服务器列表
FILE_TO_TRANSFER="/home/wangyuanjing/mqtt-plug/信义-psnsj202303622/dep/out/esccu-libmqtt-xingyi_1.0.1_arm64.deb"
REMOTE_USER="gold"
REMOTE_PASSWORD="gold"  # 注意：密码明文存储有一定的安全风险
REMOTE_SERVERS=("172.18.20.94" "172.18.20.99" "172.18.21.233" "172.18.20.126" "172.18.20.214" "172.18.21.0" "172.18.20.127")
REMOTE_PATH="/home/gold/"

# 遍历服务器列表，将文件传输到每个服务器
for SERVER in "${REMOTE_SERVERS[@]}"; do
    echo "Transferring file to $SERVER..."
    scp "$FILE_TO_TRANSFER" "$REMOTE_USER@$SERVER:$REMOTE_PATH"
    if [ $? -eq 0 ]; then
        echo "File successfully transferred to $SERVER."
    else
        echo "Failed to transfer file to $SERVER."
    fi
done
#!/bin/bash
