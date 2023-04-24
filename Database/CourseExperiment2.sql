--创建表student,course,courseselc并插入数据
create table student(
    name varchar(20) not null,
    sno char(10) primary key,
    sex char(4) check(sex in ('男', '女')),
    address char(10)
);

insert into student values(
    '李白',
    '100001',
    '男',
    '和平区'
);

insert into student values(
    '杜甫',
    '100002',
    '男',
    '河西区'
);

insert into student values(
    '李清照',
    '100003',
    '女',
    '河北区'
);

insert into student values(
    '白居易',
    '100004',
    '男',
    '红桥区'
);

insert into student values(
    '蔡琰',
    '100005',
    '女',
    '红桥区'
);

create table course(
    course_name varchar(20) unique,
    course_no char(10) primary key,
    course_teacher varchar(20),
    course_score char(1) check(course_score in ('1', '3', '5'))
);

insert into course values(
    '数学',
    'M1001',
    '奥巴马',
    '3'
);

insert into course values(
    '军事理论',
    'J2002',
    '拿破仑',
    '5'
);

insert into course values(
    '摔跤',
    'S3003',
    '普京',
    '1'
);

create table courseselc(
    no char(10) primary key,
    sno char(10) references student(sno),
    course_no char(10) references course(course_no),
    test_score int check(test_score >= 0 and test_score <= 100)
);

insert into courseselc values(
    '1',
    '100001',
    'M1001',
    70
);

insert into courseselc values(
    '2',
    '100001',
    'J2002',
    60
);

insert into courseselc values(
    '3',
    '100001',
    'S3003',
    80
);

insert into courseselc values(
    '4',
    '100002',
    'M1001',
    75
);

insert into courseselc values(
    '5',
    '100002',
    'J2002',
    85
);

insert into courseselc values(
    '6',
    '100002',
    'S3003',
    95
);

insert into courseselc values(
    '7',
    '100003',
    'M1001',
    50
);

insert into courseselc values(
    '8',
    '100003',
    'J2002',
    55
);

insert into courseselc values(
    '9',
    '100003',
    'S3003',
    45
);

insert into courseselc values(
    '10',
    '100004',
    'M1001',
    10
);

insert into courseselc values(
    '11',
    '100004',
    'J2002',
    15
);

insert into courseselc values(
    '12',
    '100004',
    'S3003',
    25
);

--1.得到所有男/女人数
select
    count(sex),
    sex
from
    student
group by
    sex;

--2.得到某一门课程(以数学为例）的选课人员清单
select
    *
from
    student
where
    sno in (
        select
            sno
        from
            courseselc
        where
            course_no='M1001'
    );

--3.得到某一门课程(以数学为例)的选课人员总数
select
    count(*)选课人数
from
    student
where
    sno in (
        select
            sno
        from
            courseselc
        where
            course_no='M1001'
    );

--4.得到某一门课程(以数学为例)的选课人员的平均成绩
select
    avg(test_score)平均成绩
from
    courseselc
where
    course_no='M1001';

select
    *
from
    courseselc;

--创建一个视图，其中包含emp表的员工编号、员工姓名、职位、雇用日期、部门编号