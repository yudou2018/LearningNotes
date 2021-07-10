Windows下：
1. 使用IIS创建FTP；
2. 选择仅指定用户可用；
3. 在控制面板-用户账户中添加新的用户yudouIpad、yudouLinux；(全改为yudou用户名)
4. 在ipad上可通过FTPManager访问，在Linux上可用浏览器和ftp命令访问。
5. 搭建好后设备需要连在同一个wifi上，否则需要更复杂的NAT配置等等。
6. 浏览器不可访问是因为浏览器的发展在逐渐淘汰FTP，例如Chorme已经公开宣布不支持FTP服务。

下载速率可达5-6MB/s


Linux下：
查看 /etc/vsftpd/vsftpd.conf找到 anon_path 可以设置分享的目录路径。
