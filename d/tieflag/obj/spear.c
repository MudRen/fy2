#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name( HIR "霸王枪" NOR, ({ "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "
霸王枪长一丈三尺七寸三分，重七十三斤七两三钱。\n
据说天下最厉害的武器就是它和传说中的其它六种兵器合成（combine）的。\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N一伸手抄起一杆$n。\n");
                set("unwield_msg", "$N将手中的$n插入地下。\n");
        }
        init_dagger(60);
        setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_combine","combine");
}

int do_combine()
{
int i,bk=0,cs=0,le=0,lo=0,pe=0,sp=0,il=0;
object commcase,me, *inv;
object bknife,csword,leavehook,lovering,peacock,spear,illquan;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
			if(base_name(inv[i]) == "/u/chuenyu/npc/obj/bknife") {bk = 1; bknife = inv[i];}
                        if(base_name(inv[i]) == "/d/tieflag/obj/csword") {cs = 1; csword = inv[i];}
                        if(base_name(inv[i]) == "/d/tieflag/obj/leavehook") {le = 1; leavehook = inv[i];}
                        if(base_name(inv[i]) == "/d/tieflag/obj/lovering") {lo = 1;  lovering = inv[i];}
                        if(base_name(inv[i]) == "/d/tieflag/npc/obj/peacock") {pe = 1; peacock = inv[i];}
                        if(base_name(inv[i]) == "/d/tieflag/obj/spear") {sp = 1; spear = inv[i];}
                        i++;
		}
                        if(me->query_skill("ill-quan")>=10) {il = 1;}
if( bk && cs && le && lo && pe && sp && il )
{
	
	bknife->move(environment(me));destruct(bknife);
        csword->move(environment(me));destruct(csword);
        leavehook->move(environment(me));destruct(leavehook);
        lovering->move(environment(me));destruct(lovering);
        peacock->move(environment(me));destruct(peacock);
	message_vision("$N把手中的几件兵器仔细研究了一番，
运用病维摩拳收发由心的用力技巧，用它们做成了一口箱子。\n",me);
	commcase = new(__DIR__"commcase");
	commcase->move(me);
        if(!me->query("m_success/大箱子"))
        {
                me->set("m_success/大箱子",1);
                me->add("score",700);

        }
	spear->move(environment(me));destruct(spear);
}
else 
message_vision("$N把手中的几件兵器仔细研究了一番．\n",this_player());

return 1;
}
