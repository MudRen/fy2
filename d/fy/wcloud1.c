inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���ƹ㳡�ڶ���֪�����������������Ƿ��Ƴ��з�ɧ���˴Ծ�֮�ء���˵����
�պ�������С��̽�������������е���š��ϱߵĿ���ÿ�궼����һ��ѡ�ο��ԣ�
ǰ�������뾩�����ԡ���������̽��ʫ̨���Ƿ�ɧ�������������ǵ���֮���ĵ�
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/song": 1,
        __DIR__"npc/xiwei": 4,
                        ]) );


        set("outdoors", "fengyun");
        set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob,room;
        int i;
        if( userp(me) && dir == "north")
	{
	room = load_object("/d/qianjin/qianjin");
	if(room && !room->query("enter_permission"))
	if(objectp(ob = present("qinwei",this_object())))
		return notify_fail(ob->name()+"����ȵ������ʹ�������֮���������˵Ȳ������ڣ�\n");	
	if( sizeof(me->query_all_condition()) != 0 )
	return notify_fail("̽��ʫ̨������ķس���\n");
	}	
	return 1;
}
