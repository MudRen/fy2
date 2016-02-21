#define SCORE_COST 10000
#define GOLD_COST 2000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name,title;	
	string *dir;
	int i;
	seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %s",e_name, c_name, title) != 3)
        return notify_fail("ָ���ʽ����bang xuelianjiao ѩ���� ����\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("������۵㲻��"+chinese_number(SCORE_COST)+
        "�㡣\n");
        gold = present("gold_money",me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("������û��"+chinese_number(GOLD_COST)+"�����ӡ�\n");	
	if(!check_legal_name(c_name) || !check_legal_name(title))
	return 1;
	c_name += "��";
	e_name += "_";
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
	return notify_fail("���봴���İ������Ļ�Ӣ�������Ѿ�������ռ���ˣ�\n");	
	if(
	!BR_D->touch_file(DATA_DIR+"guild/"+e_name) ||
	!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("��Ϸϵͳ�������⣡��֪ͨ������Ա��\n");
	me->delete("family");
	me->create_family(c_name,1,title);
	me->set("class",e_name);
	me->add("score",-SCORE_COST);
	gold->add_amount(-GOLD_COST);
 	message("system",
	"\n\n\n
			��"+c_name+"��"+"�ڽ����г����ˣ�\n\n\n",
			users() );
    return 1;
}
 
int help(object me)
{
    write(@HELP
�����ڷ����г����Լ��İ��ɣ�

ָ���ʽ: 
bang xuelianjiao ѩ���� ����

��ָ�����㴴��һ���µİ�ɣ���̡� 
������Ϊѩ���̽�����

������

bang bluedress ����¥ �ܹ�
��������¥������Ϊ����¥�ܹܡ�
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
                write("�Բ����������ֱ���������ʮ��������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

