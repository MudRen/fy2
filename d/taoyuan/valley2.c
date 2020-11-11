inherit ROOM;
void create()
{
        set("short", "山谷");
        set("long", @LONG
树林到了此处逐渐变得稀疏起来，眼前赫然出现一座千层叠翠、万里点苍的山峰，
围成一处幽谷，中有一泓清潭，泉水从峰间奔流而下，喷珠泄玉，直入清潭。几只白尾
巴的野兔，正在潭边悠闲的喝水。此处空气清凉湿润，沁人心肺，四周却看不见任何明
显的出路，看来，你只好四处转转看了。
LONG
        );

	set("item_desc", ([
	"pond" : "潭水明澈见底，里面小鱼小虾皆若空游无所依。\n",
	"清潭" : "潭水明澈见底，里面小鱼小虾皆若空游无所依。\n",
	]) );

        set("outdoors","taoyuan");
        set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_around", "around");

}

int do_around(string arg)
{
	object me, room;

	me = this_player();
tell_object(me, "你转来转去，也没找到出口，你迷了路！！\n\n");
        room = find_object(__DIR__"valley");
	if(!objectp(room)) room=load_object(__DIR__"valley");
	me->move(room);

	return 1;
}

