#!/bin/bash
#用户管理系统
main() 
{   
    #只能是root用户才可以执行
    if [[ $EUID -ne 0 ]]
    then 
	    echo "无root权限,请在运行脚本前加sudo或切换为root用户运行此脚本";
	    exit 9;
    fi    
    while :
    do
        menu
        read -p "请输入功能编号:" choice
        case "${choice}" in
            "1") useraddition;;
            "2") usermodify;;
            "3") usercheck;;
            "4") userdelete;;
            "5") userbatch;;
            "6") groupaddition;;
            "7") groupmodify;;
            "8") groupcheck;;
            "9") groupdelete;;
            "10") groupbatch;;
            "0") quit;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac
    done
}
#用户菜单
menu()
{  
    #清屏
    clear;
    echo "  
    //==============================================================\\
    |                      Linux用户管理系统                         |
    -----------------------------------------------------------------
    |                      1、创建用户                               |
    |                      2、修改用户                               |
    |                      3、查看用户                               |
    |                      4、删除用户                               |
    |                      5、批量管理用户                           |
    |                      6、创建用户组                             |
    |                      7、修改用户组                             |
    |                      8、查看用户组                             |
    |                      9、删除用户组                             |
    |                      10、批量管理用户组                        |
    |                      0、退出脚本                               |
    -----------------------------------------------------------------
    "
}
#暂停
pause()
{
    read -p "按回车键继续..."
}
#创建用户
useraddition()
{
    read -p "请输入所需创建用户的用户名:" usernamea;
    grep "^$usernamea" /etc/passwd >& /dev/null
    if [ $? -ne 0 ]
    then
        read -p "请输入UID:" useruid;      
    else 
        echo "用户已存在";
        useraddition;
    fi
    grep "^$useruid" /etc/passwd >& /dev/null
    if [ $? -ne 0 ]
    then
        read -p "请输入初始用户组:" usergroup; 
        else 
            echo "用户已存在";
            useraddition;
    fi
    grep "^$usergroup" /etc/group >& /dev/null
    if [ $? -eq 0 ]
    then
        useradd -u $useruid -g $usergroup -s /bin/bash $usernamea;
        echo "用户创建成功";
        read -p "请输入密码:" userpasswd;
        echo ${usernamea}:${userpasswd} | chpasswd;
        echo "密码设置成功"
    else 
        echo "用户组不存在,请创建用户组后再试";
        useraddition;
    fi 
    pause;
}
#修改用户
usermodify()
{
    while :
    do
        clear;
        echo "
        |                      1、修改用户名                             |
        |                      2、修改用户UID                            |
        |                      3、修改用户密码                           |
        |                      4、修改初始用户组                         |
        |                      0、返回主菜单                             |
        "
        read -p "请输入功能编号:" choice1
        case "${choice1}" in
            "1") usernamemod;;
            "2") useruidmod;;
            "3") userpasswdmod;;
            "4") usergroupmod;;
            "0") back;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac
    done
}
#修改用户名
usernamemod()
{
    read -p "请输入所需修改用户的用户名:" usernamem;
    grep "^$usernamem" /etc/passwd >& /dev/null
    if [ $? -eq 0 ]
    then
        read -p "请输入修改后的用户名:" usernamema;
        grep "^$usernamema" /etc/passwd >& /dev/null
        if [ $? -ne 0 ]
        then
            usermod -l $usernamema $usernamem; 
            echo "用户名修改成功";    
        else 
            echo "用户已存在";
            usernamemod;
        fi
    else 
        echo "用户不存在";
        usernamemod;
    fi
    pause;
}
#修改用户UID
useruidmod()
{
    read -p "请输入所需修改用户的用户名:" usernamem;
    grep "^$usernamem" /etc/passwd >& /dev/null
    if [ $? -eq 0 ]
    then
        read -p "请输入修改后的用户UID:" useruidma;
        grep "^$useruidma" /etc/passwd >& /dev/null
        if [ $? -ne 0 ]
        then
            usermod -u $useruidma $usernamem;  
            echo "UID修改成功";   
        else 
            echo "用户UID已存在";
            useruidmod;
        fi
    else 
        echo "用户不存在";
        useruidmod;
    fi
    pause;
}
#修改用户密码
userpasswdmod()
{
    read -p "请输入所需修改用户的用户名:" usernamem;
    grep "^$usernamem" /etc/passwd >& /dev/null
    if [ $? -eq 0 ]
    then
        read -p "请输入修改后的用户密码:" userpasswdma;
        echo ${usernamem}:${userpasswdma} | chpasswd;   
        echo "密码修改成功";
    else 
        echo "用户不存在";
        userpasswdmod;
    fi
    pause;
}
#修改初始用户组
usergroupmod()
{
    read -p "请输入所需修改用户的用户名:" usernamem;
    grep "^$usernamem" /etc/passwd >& /dev/null
    if [ $? -eq 0 ]
    then
        read -p "请输入修改后的用户初始组:" usergroupma;
        grep "^$usergroupma" /etc/group >& /dev/null
        if [ $? -eq 0 ]
        then
            usermod -g $usergroupma $usernamem;
            echo "用户初始组修改成功";     
        else 
            echo "用户组不存在";
            usergroupmod;
        fi
    else 
        echo "用户不存在";
        usergroupmod;
    fi
    pause;
}
#查看用户
usercheck()
{
    while :
    do
        clear;
        echo "
        |                      1、查看全部用户                           |
        |                      2、查看单个用户                           |
        |                      0、返回主菜单                             |
        "
        read -p "请输入功能编号:" choice2
        case "${choice2}" in
            "1") usercheckall;;
            "2") usercheckone;;
            "0") back;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac
    done
}
#查看全部用户
usercheckall()
{
    less /etc/passwd | awk -F: '$3>=1000' ;
    pause;
}
#查看单个用户
usercheckone()
{
    read -p "请输入需要查看用户的用户名:" usernames;
    grep "^$usernames" /etc/passwd >& /dev/null
    if [ $? -eq 0 ]
    then
        less /etc/passwd |  awk -F: '$3>=1000 && $1=="'$usernames'"';
    else 
        echo "用户不存在";
        usercheckone;
    fi
    pause;
}
#删除用户
userdelete()
{
    read -p "请输入需要删除用户的用户名:" usernamed;
    grep "^$usernamed" /etc/passwd >& /dev/null
    if [ $? -eq 0 ]
    then
        userdel -r $usernamed;
        echo "用户删除成功";
    else 
        echo "用户不存在";
        userdelete;
    fi
    pause;
}
#批量管理用户
userbatch()
{
    while :
    do
        clear;
        echo "
        |                      1、批量创建用户                           |
        |                      2、批量修改用户名                         |
        |                      3、批量修改用户UID                        |
        |                      4、批量修改用户初始组                     |
        |                      5、批量修改用户密码                       |
        |                      6、批量删除用户                           |
        |                      0、返回主菜单                             |
        "
        read -p "请输入功能编号:" choice3
        case "${choice3}" in
            "1") usersadd;;
            "2") usersmodname;;
            "3") usersmoduid;;
            "4") usersmodgroup;;
            "5") usersmodpasswd;;
            "6") usersdel;;
            "0") back;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac
    done
}
#批量创建用户
usersadd()
{
    read -p "请输入需要创建的用户个数:" num;
    for((i=0;i<$num;i++))
    do
        useraddition;
    done 
    pause;
}
#批量修改用户名
usersmodname()
{
    read -p "请输入需要修改的用户个数:" num;
    for((i=0;i<$num;i++))
    do
        usernamemod;
    done 
    pause;
}
#批量修改用户UID
usersmoduid()
{
    read -p "请输入需要修改的用户个数:" num;
    for((i=0;i<$num;i++))
    do
        useruidmod;
    done 
    pause;
}
#批量修改用户初始组
usersmodgroup()
{
    read -p "请输入需要修改的用户个数:" num;
    for((i=0;i<$num;i++))
    do
        usergroupmod;
    done 
    pause;
}
#批量修改用户密码
usersmodpasswd()
{
    read -p "请输入需要修改的用户个数:" num;
    for((i=0;i<$num;i++))
    do
        userpasswdmod;
    done 
    pause;
}
#批量删除用户
usersdel()
{
    read -p "请输入需要删除的用户个数:" num;
    for((i=0;i<$num;i++))
    do
        userdelete;
    done 
    pause;
}
#创建用户组
groupaddition()
{
    read -p "请输入所需创建用户组的组名:" groupnamea;
    grep "^$groupnamea" /etc/group >& /dev/null
    if [ $? -ne 0 ]
    then
        read -p "是否指定GID:<y/n>" uidflag;      
    else 
        echo "用户组已存在";
        groupaddition;
    fi
    if [[ $uidflag == y || $uidflag == Y ]]
    then
        read -p "请输入GID:" groupuida; 
        grep "^$groupuida" /etc/group >& /dev/null
        if [ $? -ne 0 ]
        then
            groupadd -g $groupuida $groupnamea;
            echo "用户组创建成功";
        else 
            echo "GID已存在";
            groupaddition;
        fi
    elif [[ $uidflag == n || $uidflag == N ]]
    then
        groupadd $groupnamea;
        echo "用户组创建成功";
    else
        echo "输入有误,请重新输入";
        groupaddition;
    fi
    pause;
}
#修改用户组
groupmodify()
{
    while :
    do
        clear;
        echo "
        |                      1、修改用户组名                           |
        |                      2、修改用户组GID                          |
        |                      0、返回主菜单                             |
        "
        read -p "请输入功能编号：" choice4
        case "${choice4}" in
            "1") groupnamemod;;
            "2") groupuidmod;;
            "0") back;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac 
    done
}
#修改用户组名
groupnamemod()
{
    read -p "请输入所需修改用户组的组名:" groupnamem;
    grep "^$groupnamem" /etc/group >& /dev/null
    if [ $? -eq 0 ]
    then
        read -p "请输入修改后的用户组名:" groupnamema;
        grep "^$groupnamema" /etc/group >& /dev/null
        if [ $? -ne 0 ]
        then
            groupmod -n $groupnamema $groupnamem; 
            echo "用户组名修改成功";    
        else 
            echo "用户组已存在";
            groupnamemod;
        fi
    else 
        echo "用户组不存在";
        groupnamemod;
    fi
    pause;
}
#修改用户组GID
groupuidmod()
{
    read -p "请输入所需修改用户组的用户组名:" groupnamem;
    grep "^$groupnamem" /etc/group >& /dev/null
    if [ $? -eq 0 ]
    then
        read -p "请输入修改后的用户组GID:" groupuidma;
        grep "^$groupuidma" /etc/group >& /dev/null
        if [ $? -ne 0 ]
        then
            groupmod -g $groupuidma $groupnamem;  
            echo "GID修改成功";   
        else 
            echo "用户组GID已存在";
            groupuidmod;
        fi
    else 
        echo "用户组不存在";
        groupuidmod;
    fi
    pause;
}
#查看用户组
groupcheck()
{
    while :
    do
        clear;
        echo "
        |                      1、查看全部用户组                         |
        |                      2、查看单个用户组                         |
        |                      0、返回主菜单                             |
        "
        read -p "请输入功能编号：" choice5
        case "${choice5}" in
            "1") groupcheckall;;
            "2") groupcheckone;;
            "0") back;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac
    done
}
#查看全部用户组
groupcheckall()
{
    less /etc/group | awk -F: '$3>=1000' ;
    pause;
}
#查看单个用户组
groupcheckone()
{
    read -p "请输入需要查看用户组的用户组名:" groupnames;
    grep "^$groupnames" /etc/group>& /dev/null
    if [ $? -eq 0 ]
    then
        less /etc/group |  awk -F: '$3>=1000 && $1=="'$groupnames'"';
    else 
        echo "用户组不存在";
        groupcheckone;
    fi
    pause;
}
#删除用户组
groupdelete()
{
    read -p "请输入需要删除用户组的用户组名(删除前请确保用户组内已无任何用户):" groupnamed;
    grep "^$groupnamed" /etc/group >& /dev/null
    if [ $? -eq 0 ]
    then
        groupdel  $groupnamed;
        echo "用户组删除成功";
    else 
        echo "用户组不存在";
        userdelete;
    fi
    pause;
}
#批量管理用户组
groupbatch()
{
    while :
    do
        clear;
        echo "
        |                      1、批量创建用户组                         |
        |                      2、批量修改用户组名                       |
        |                      3、批量修改用户组GID                      |
        |                      4、批量删除用户组                         |
        |                      0、返回主菜单                             |
        "
        read -p "请输入功能编号：" choice6
        case "${choice6}" in
            "1") groupsadd;;
            "2") groupsmodname;;
            "3") groupsmoduid;;
            "4") groupsdel;;
            "0") back;;
            *) echo "请输入正确的功能编号!";
            pause;;
        esac
    done
}
#批量创建用户组
groupsadd()
{
    read -p "请输入需要创建的用户组个数:" num;
    for((i=0;i<$num;i++))
    do
        groupaddition;
    done 
    pause;
}
#批量修改用户组名
groupsmodname()
{
    read -p "请输入需要修改的用户组个数:" num;
    for((i=0;i<$num;i++))
    do
        groupnamemod;
    done 
    pause;
}
#批量修改用户组GID
groupsmoduid()
{
    read -p "请输入需要修改的用户组个数:" num;
    for((i=0;i<$num;i++))
    do
        groupuidmod;
    done 
    pause;
}
#批量删除用户组
groupsdel()
{
    read -p "请输入需要删除的用户组个数:" num;
    for((i=0;i<$num;i++))
    do
        groupdelete;
    done 
    pause;
}
#返回主菜单
back()
{
    main
}
#退出脚本
quit()
{
    echo "感谢您的使用,再见";
    exit 0;
}
main