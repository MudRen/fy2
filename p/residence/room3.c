inherit ROOM;
void create ()
{
  set ("short", "��Ϫ̶");
  set ("long", @LONG
��Ϫ̶����������ˮ�������������Ͽ���С�ɽȪ�Ҹ�ӿ��������к����
Ϫ��أ�׳�����裬��������ˮ��ʯ������̽��ӣ����׳����Ϫ��Ϫǰ���²�
԰�������̣������˱ǡ���ͨ�裬����گʱ��������ֲ�����׿���ɽ������ͦ
�㣬����ʮ�����
LONG);
        set("exits", ([ 
  "south" : __DIR__"room2",
  "north" : __DIR__"room4",
]));
  	set("coor/x",10);
	set("coor/y",2020);
	set("coor/z",20);
	set("owner","public");
	setup();
  replace_program(ROOM);

}

