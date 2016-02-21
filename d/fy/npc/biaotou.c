
// written by Cheng Bao
inherit NPC;

mapping *way;
object cart;
object *protector;
mapping *read_table(string);
void give_reward();
void to_rob();
void be_protect();
void create()
{
	object ob;
	set_name("����ͷ", ({ "biaotou" }) );
	set("gender", "����" );
	set("age", 25);
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("vendetta_mark", "authority");
	set("per",2);
	set("chat_chance", 15);
    set("chat_msg",({
    	"����ͷ�ȵ����������˵������ˡ���\n",
    	"����ͷ�ȵ��������߿��ߣ���͵������\n",
    }) );
    set("chat_chance_combat",90);
    set("chat_msg_combat", ({
    	"����ͷ�󺰵����������ˣ����˽����ˡ���\n",
    	(: be_protect :),
    }) );
	
	set("force",500);
	set("max_force",500);
	set("force_factor",2);
	set_skill("blade",50);
	set_skill("shortsong-blade",50);
	set_skill("force",40);
	set_skill("parry",150);
	set_skill("dodge",150);
	map_skill("blade","shortsong-blade");
	map_skill("parry","spring-blade");
	setup();
  	add_money("silver", 50);
    carry_object(__DIR__"obj/jinzhuang")->wear();
    carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/example/wineskin");

}
void init()
{;}
void go()
{
	int i,j;
	object robber;
	string *cmds;
	remove_call_out("go");
	for(i=0;i<sizeof(way);i++)
	{
		if (base_name(environment()) != way[i]["room_file"]) continue;
		cmds=explode(way[i]["cmd_table"],";");
		break;
	}
	robber=present("gangster",environment());
	if (this_object()->is_fighting() || (robber && robber->name()=="ɽ���ٷ�"))
	{
		command("say ��������");
		call_out("go",15);
		return;
	}
	if (random(100)<15)
	{
		to_rob();
		call_out("go",15);
		return;
	}
	if (i>=sizeof(way))
	{   
		random_move();
		cart->move(environment());
		message_vision("�ڳ�¡¡ʻ�˹�����\n",this_object());
		call_out("go",5);
		return;
	}
	for(j=0;j<sizeof(cmds);j++)
		command(cmds[j]);
	cart->move(environment());
	message_vision("�ڳ�¡¡ʻ�˹�����\n",this_object());
	if (way[i]["delay_time"]<0)
	{
		give_reward();
		return;
	}
	call_out("go",way[i]["delay_time"]);
	return;
}	
void be_protect()
{
	int i,j,flag;
	object *inv,*enemy;
	
	inv=all_inventory(environment());
	enemy=query_enemy();
// if one of the protectors wants to kill... then heis out of the loop
	for(j=0;j<sizeof(enemy);j++)
		enemy[j]->delete_temp("protecting");

	for (i=0;i<sizeof(inv);i++)
		if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
		{
			flag=1;
			for(j=0;j<sizeof(enemy);j++)
			{
				inv[i]->kill_ob(enemy[j]);
				enemy[j]->kill_ob(inv[i]);
				enemy[j]->remove_killer(this_object());
				remove_killer(enemy[j]);
			}
	    }
	if(!flag) return;
	message_vision("$N�����������Ǹ����ϣ���\n",this_object());
	
}        
void get_quest(string file)
{   
	way=read_table(file);
}
void to_rob()
{
	int i;
	object robber;
	
	message_vision("��Ȼ������һȺ�ٷˣ�\n",this_object());
	for (i=0;i<=random(5)+1;i++)
	{
		robber=new(__DIR__"gangster");
		robber->move(environment());
		robber->set("combat_exp",20000+random(200000));
		robber->kill_ob(this_object());
		this_object()->kill_ob(robber);
		robber->set_leader(this_object());
	}
	be_protect();
	
}
	
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}
void set_protector(object *prot)
{	protector=prot;	}
object *query_protector()
{	return protector;	}

void set_cart(object dartcart)
{	cart=dartcart;	}
object query_cart()
{	return cart;	}

void die()
{
	object killer;
	object *inv,*pro_team;
	int values;
	int i;
	
	values=0;
	killer=query_temp("last_damage_from");
	if (objectp(cart))
	{
		
		if (arrayp(protector)) 
		{
		values*=2;
		pro_team=({0});
		if (sizeof(pro_team))
		{
			for (i=0;i<sizeof(protector);i++)
			{
				if (objectp(protector[i])) 
					pro_team+=({protector[i]});
			}
			if (!sizeof(pro_team))//���ڵ�quit���
			{
				destruct(cart);
				::die();
				return;
			}
			values/=sizeof(pro_team);
			for(i=0;i<sizeof(pro_team);i++)
			{
				if (!objectp(pro_team[i])) continue;
				if(!intp(pro_team[i]->query("deposit")) )
					pro_team[i]->set("deposit",0);
				pro_team[i]->add("deposit",-values);
				pro_team[i]->add("score",-20);
				pro_team[i]->save();
			}
		
		}
		}
/*		else
		{
			if(!intp(protector->query("deposit")))
				protector->set("deposit",0);
			protector->add("deposit",-values);
			protector->save();
		}*/
		
		if (objectp(killer))
		{
			command("chat ������"+killer->name()+"�����ˣ�");
			message_vision("$N���ڳ������������е�������\n",killer);
			inv=all_inventory(cart);
			for(i=0;i<sizeof(inv);i++)
			{
				values+=inv[i]->value();
				if (userp(killer))
				{
					inv[i]->move(killer);
					killer->add("score",-10);
				}
				else
					destruct(inv[i]);
			}
		}
	}
	::die();
}
void give_reward()
{   
	object *inv,*pro_team;
	int values,i,reward;

		
		reward=random(500)+1000;
		inv=all_inventory(cart);
		for(i=0;i<sizeof(inv);i++)
			values+=inv[i]->value();
		
		if (arrayp(protector)) 
		{
		values/=10;
		pro_team=protector;
		if (sizeof(pro_team))
		{
			values/=sizeof(pro_team);
			reward/=sizeof(pro_team);
			for(i=0;i<sizeof(pro_team);i++)
			{
				if (!objectp(pro_team[i])) continue;
				if(!intp(pro_team[i]->query("deposit")))
					pro_team[i]->set("deposit",0);
				pro_team[i]->add("deposit",values);
				pro_team[i]->add("combat_exp",reward);
				pro_team[i]->add("potential",reward/10);
				if(!pro_team[i]->query("m_success/����"))
				{
					pro_team[i]->set("m_success/����",1);
					pro_team[i]->add("score", 200);
				}
				pro_team[i]->save();
			}
		}
/*		else
		{
			if(!intp(protector->query("deposit")) )
					protector->set("deposit",0);
			protector->set("deposit",protector->query("deposit")+values);
			protector->add("combat_exp",reward);  			
			protector->add("score",reward/100);   			
			protector->save();
			protector->add("potential",reward/10);		
		}*/
	}
	
	destruct(cart);
	inv=all_inventory(environment());

	for (i=0;i<sizeof(inv);i++)
		if (inv[i]->query_temp("protecting")==cart && !userp(inv[i]))
			destruct(inv[i]);
	destruct(this_object());
	
	return;
}
void go_now()
{
	call_out("go",10);
}
