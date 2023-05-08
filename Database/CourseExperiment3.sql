--创建图书管理库的图书、读者和借阅三个基本表的表结构：
create table book(
    book_id number(10),
    sort varchar2(10),
    book_name varchar2(50),
    writer varchar2(10),
    output varchar2(50),
    price number(3)
);

create table reader(
    reader_id number(3),
    company varchar2(20),
    name varchar2(10),
    sex varchar2(3),
    grade varchar2(10),
    addr varchar2(50)
);

create table borrow (
    reader_id number(3),
    book_id number(10),
    borrow_date date
);

--插入数据

--book表
insert into book values(
    445501,
    'TP3/12',
    '数据库导论',
    '王强',
    '科学出版社',
    17.90
);

insert into book values(
    445502,
    'TP3/12',
    '数据库导论',
    '王强',
    '科学出版社',
    17.90
);

insert into book values(
    445503,
    'TP3/12',
    '数据库导论',
    '王强',
    '科学出版社',
    17.90
);

insert into book values(
    332211,
    'TP5/10',
    '计算机基础',
    '李伟',
    '高等教育出版社',
    18.00
);

insert into book values(
    112266,
    'TP3/12',
    'FoxBASE',
    '张三',
    '电子工业出版社',
    23.60
);

insert into book values(
    665544,
    'TS7/21',
    '高等数学',
    '刘明',
    '高等教育出版社',
    20.00
);

insert into book values(
    114455,
    'TR9/12',
    '线性代数',
    '孙业',
    '北京大学出版社',
    20.80
);

insert into book values(
    113388,
    'TR7/90',
    '大学英语',
    '胡玲',
    '清华大学出版社',
    12.50
);

insert into book values(
    446601,
    'TP4/13',
    '数据库基础',
    '马凌云',
    '人民邮电出版社',
    22.50
);

insert into book values(
    446602,
    'TP4/13',
    '数据库基础',
    '马凌云',
    '人民邮电出版社',
    22.50
);

insert into book values(
    446603,
    'TP4/13',
    '数据库基础',
    '马凌云',
    '人民邮电出版社',
    22.50
);

insert into book values(
    449901,
    'TP4/14',
    'FoxPro大全',
    '周虹',
    '科学出版社',
    32.70
);

insert into book values(
    449902,
    'TP4/14',
    'FoxPro大全',
    '周虹',
    '科学出版社',
    32.70
);

insert into book values(
    118801,
    'TP4/15',
    '计算机网络',
    '黄力钧',
    '高等教育出版社',
    21.80
);

insert into book values(
    118802,
    'TP4/15',
    '计算机网络',
    '黄力钧',
    '高等教育出版社',
    21.80
);

--reader表

insert into reader values(
    111,
    '信息系',
    '王维利',
    '女',
    '教授',
    '1号楼424'
);

insert into reader values(
    112,
    '财会系',
    '李立',
    '男',
    '副教授',
    '2号楼316'
);

insert into reader values(
    113,
    '经济系',
    '张三',
    '男',
    '讲师',
    '3号楼105'
);

insert into reader values(
    114,
    '信息系',
    '周华发',
    '男',
    '讲师',
    '1号楼316'
);

insert into reader values(
    115,
    '信息系',
    '赵正义',
    '男',
    '工程师',
    '1号楼224'
);

insert into reader values(
    116,
    '信息系',
    '李明',
    '男',
    '副教授',
    '1号楼318'
);

insert into reader values(
    117,
    '计算机系',
    '李小峰',
    '男',
    '助教',
    '1号楼214'
);

insert into reader values(
    118,
    '计算机系',
    '许鹏飞',
    '男',
    '助工',
    '1号楼216'
);

insert into reader values(
    119,
    '计算机系',
    '刘大龙',
    '男',
    '教授',
    '1号楼318'
);

insert into reader values(
    120,
    '国际贸易',
    '李雪',
    '男',
    '副教授',
    '4号楼506'
);

insert into reader values(
    121,
    '国际贸易',
    '李爽',
    '女',
    '讲师',
    '4号楼510'
);

insert into reader values(
    122,
    '国际贸易',
    '王纯',
    '女',
    '讲师',
    '4号楼512'
);

insert into reader values(
    123,
    '财会系',
    '沈小霞',
    '女',
    '助教',
    '2号楼202'
);

insert into reader values(
    124,
    '财会系',
    '朱海',
    '男',
    '讲师',
    '2号楼210'
);

insert into reader values(
    125,
    '财会系',
    '马英明',
    '男',
    '副教授',
    '2号楼212'
);

--borrow表

insert into borrow values(
    112,
    445501,
    '19-3月-2006'
);

insert into borrow values(
    125,
    332211,
    '12-2月-2006'
);

insert into borrow values(
    111,
    445503,
    '21-8月-2006'
);

insert into borrow values(
    112,
    112266,
    '14-3月-2006'
);

insert into borrow values(
    114,
    665544,
    '21-10月-2006'
);

insert into borrow values(
    120,
    114455,
    '02-11月-2006'
);

insert into borrow values(
    120,
    118801,
    '18-10月-2006'
);

insert into borrow values(
    119,
    446603,
    '12-11月-2006'
);

insert into borrow values(
    112,
    449901,
    '23-10月-2006'
);

insert into borrow values(
    115,
    449902,
    '21-8月-2006'
);

insert into borrow values(
    118,
    118801,
    '10-9月-2006'
);

--创建一个不带参数据的存储过程，统计并输出2006年每个月份的图书借出的册数
create or replace procedure pro1 as
    var_id   borrow.book_id%type;
    var_date borrow.borrow_date%type;
begin
    for i in 1..12 loop
        select
            count(*) into var_id
        from
            borrow
        where
            to_char(borrow_date,
            'mm') = to_char(to_date(i,
            'mm'),
            'mm');
        dbms_output.put_line('2006年'
            || i
            || '月份的图书借出的册数为：'
            || var_id);
    end loop;
end;
/

--将上面的存储过程修改为带参的存储过程，根据输入的年份，统计并输出该年份每个月份的图书借出的册数。
create or replace procedure pro2(
    var_year number
) as
    var_id   borrow.book_id%type;
    var_date borrow.borrow_date%type;
begin
    for i in 1..12 loop
        select
            count(*) into var_id
        from
            borrow
        where
            to_char(borrow_date,
            'yyyy') = to_char(to_date(var_year,
            'yyyy'),
            'yyyy')
            and to_char(borrow_date,
            'mm') = to_char(to_date(i,
            'mm'),
            'mm');
        dbms_output.put_line(var_year
            || '年'
            || i
            || '月份的图书借出的册数为：'
            || var_id);
    end loop;
end;
/

--创建一个带参的存储过程，根据输入的读者的姓名，输出该读者的借书情况，包括借书的日期、书名、出版社、单价及应归还的日期（假设最长借期为30天）
create or replace procedure pro3(
    var_reader_name in reader.name%type
) as
    var_date        borrow.borrow_date%type;
    var_name        book.book_name%type;
    var_pub         book.output%type;
    var_price       book.price%type;
    var_return_date borrow.borrow_date%type;
    var_reader      reader.name%type;
begin
    for info in (
        select
            borrow.borrow_date,
            book.book_name,
            book.output,
            book.price,
            reader.name
        from
            borrow,
            book,
            reader
        where
            borrow.book_id = book.book_id
            and reader.reader_id = borrow.reader_id
    ) loop
        var_date := info.borrow_date;
        var_name := info.book_name;
        var_pub := info.output;
        var_price := info.price;
        var_return_date := var_date + 30;
        var_reader := info.name;
        if(var_reader_name=var_reader) then
            dbms_output.put_line('读者姓名：'
                || var_reader_name
                || '，借书日期：'
                || var_date
                || '，书名：'
                || var_name
                || '，出版社：'
                || var_pub
                || '，单价：'
                || var_price
                || '，应归还日期：'
                || var_return_date);
        end if;
    end loop;
end;
/