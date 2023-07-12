#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct s_data{
int age;
char *name;
}t_data;

void	update_age(t_data v)
{
	v.age++;
	v.name[0] = 'T';
	printf("%p\n", &v.age);
}

void update_age_2(t_data *v)
{
	v->age++;
	v->name[0] = 'C';
}


int main(void)
{
	t_data v;
	v.age = 39;
	v.name = strdup("luis");

	printf("%d\n", v.age);
	printf("%s\n", v.name);
	update_age(v);
	printf("%d\n", v.age);
	printf("%s\n", v.name);
	printf("%p\n", &v.age);

	update_age_2(&v);
	printf("%d\n", v.age);
	printf("%s\n", v.name);
	
	return(0);
}