// apprentice.c

#include <dbase.h>

int is_apprentice_of(object ob)
{
	mapping family;
	
	if( !mapp(family = query("family")) ) return 0;

	if( family["master_id"] == (string)ob->query("id")
	&&	family["master_name"] == (string)ob->query("name") 
	&&	family["family_name"] == (string)ob->query("family/family_name"))
		return 1;

	return 0;	
}
int is_couple_of(object ob)
{
	if((string)query("marry") == (string)ob->query("id") &&
	   (string)query("id") == (string)ob->query("marry"))
	return 1;
        return 0;
}

void assign_apprentice(string title, int privs)
{
	mapping family;

	if( !mapp(family = query("family")) ) return;

	family["title"] = title;
	family["privs"] = privs;

	if( userp(this_object()) || !query("title") ) {
		if( family["generation"]==1 )
			set("title", family["family_name"] + family["title"]);
		else
			set("title", sprintf("%s��%s��%s", family["family_name"],
				chinese_number(family["generation"]), family["title"]));
	}
}

// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
	mapping family;

	family = allocate_mapping(6);

	family["family_name"] = family_name;
	family["generation"] = generation;

	set("family", family);

	// priv = -1 for ALL privileges.
	assign_apprentice( title, -1 );
}

int recruit_apprentice(object ob)
{
	mapping my_family, family;
	string name;
	if( ob->is_apprentice_of( this_object() ) )	return 0;
	if( !mapp(my_family = query("family")) ) return 0;
	if(!name = query("student_title"))
	name = "����";
	family = allocate_mapping(sizeof(my_family));
	family["master_id"] = query("id");
	family["master_name"] = query("name");
	family["family_name"] = my_family["family_name"];
	family["generation"] = my_family["generation"] + 1;
	family["enter_time"] = time();
	ob->set("family", family);
	ob->set("class", query("class"));
	ob->assign_apprentice(name, 0);
	return 1;
}

