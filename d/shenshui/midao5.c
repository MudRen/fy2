// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
ת�˼����䣬�붴�����ǰ�����ֲ�����ָ����Χ��ʱ����С����
�ӹ���ɳɳ����������η�������ͷȴ�Բ�֪��ʱ�ĵ�·����������Ҳ��
���嶫���ϱ���ֻ�ô����ŷ���׳�ŵ�����������ǰ�ߡ�
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"midao6",
      "east" : __DIR__"midao2",
   ]));
	set("coor/x",90);
	set("coor/y",12060);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}