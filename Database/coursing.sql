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
set serveroutput on

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