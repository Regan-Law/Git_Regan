--declare
--    re_goods system.goods%rowtype;
--    cursor our_all_goods is
--        select
--            *
--        from
--            system.goods;
--begin
--    open our_all_goods;
--    loop
--        fetch our_all_goods into re_goods;
--        exit when our_all_goods%notfound;
--        dbms_output.put_line(re_goods.g_id
--            ||' '
--            ||re_goods.g_name
--            ||' '
--            ||re_goods.g_price);
--    end loop;
--    close our_all_goods;
--end;
--set serveroutput on

declare
    cursor cur_goods(tid goods.g_id%type) is
        select
            *
        from
            goods
        where
            g_id = tid;
begin
    for rec_goods in cur_goods(1) loop
        dbms_output.put_line(rec_goods.g_id
            ||' '
            ||rec_goods.g_name
            ||' '
            ||rec_goods.g_price);
    end loop;
end;
/

set serveroutput on

declare
    pempno  number;
    yearsal number;
begin
    pempno:=7369;
    yearsal:=getyearsal(pempno);
    dbms_output.put_line(yearsal);
end;
/

--创建函数，查询姓名为james的员工的年薪
create or replace function getyearsal(
    pempno in number
) return number is
    v_yearsal number;
begin
    select
        sal*12 into v_yearsal
    from
        emp
    where
        empno = pempno;
    return v_yearsal;
end;
/

--调用函数
declare
    pempno  number;
    yearsal number;
begin
    pempno:=7369;
    yearsal:=getyearsal(pempno);
    dbms_output.put_line(yearsal);
end;
/

--创建函数，查询姓名为james的员工的员工编号，职位，月薪，返回多个值
create or replace function getemp(
    pempno in number
) return emp%rowtype is
    v_emp emp%rowtype;
begin
    select
        * into v_emp
    from
        emp
    where
        empno = pempno;
    return v_emp;
end;
/

--调用函数
declare
    pempno number;
    v_emp  emp%rowtype;
begin
    pempno:=7369;
    v_emp:=getemp(pempno);
    dbms_output.put_line(v_emp.empno
        ||' '
        ||v_emp.ename
        ||' '
        ||v_emp.job
        ||' '
        ||v_emp.sal);
end;
/