import mysql.connector
from mysql.connector import Error
import time

def update_enable_field(host, user, password, database, user_id, new_enable_value):
    connection = None
    try:
        # 连接到 MySQL 数据库
        connection = mysql.connector.connect(
            host=host,
            user=user,
            password=password,
            database=database
        )
        
        if connection.is_connected():
            print("成功连接到 MySQL 数据库")

            # 创建一个游标对象
            cursor = connection.cursor()

            # 更新 `enable` 字段的 SQL 语句
            update_query = """
            UPDATE users
            SET enable = %s
            WHERE id = %s
            """

            # 执行 SQL 语句
            cursor.execute(update_query, (new_enable_value, user_id))
            
            # 提交更改
            connection.commit()

            print(f"成功更新 `users` 表中 id 为 {user_id} 的 `enable` 字段为 {new_enable_value}")

    except Error as e:
        print(f"数据库错误: {e}")
    
    finally:
        # if connection.is_connected():
        #     cursor.close()
        #     connection.close()
        print("MySQL 数据库连接已关闭")

def toggle_enable(host, user, password, database, user_id):
    enable_value = 0  # 初始值
    while True:
        # 更新 enable 字段
        update_enable_field(host, user, password, database, user_id, enable_value)
        
        # 交替值
        enable_value = 1 - enable_value
        
        # 等待 5 秒钟
        time.sleep(30)

if __name__ == "__main__":
    # 数据库连接信息
    db_host = '192.168.111.193' #'192.168.111.193:3306'  # 数据库主机
    db_user = 'mosquitto_user'  # 数据库用户名
    db_password = 'Gold@mosquitto'  # 数据库密码
    db_name = 'db_mosquitto'  # 数据库名称

    # 更新字段的参数
    user_id = 1                 # 要更新的用户 ID

    # 启动交替更新 `enable` 字段的函数
    toggle_enable(db_host, db_user, db_password, db_name, user_id)
