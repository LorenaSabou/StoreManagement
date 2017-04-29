#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <crtdbg.h>	
using namespace std;



int main() {


	system("color f4");

	Coat a{ 33, "blue", 65, 3, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/redingot%C4%83-din-in-c719012p4348016.html",150 };
	Coat b{ 33, "red", 190, 2, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-cu-vol%C4%83na%C5%9F-la-man%C5%9Fete-c719012p4467046.html",100 };
	Coat c{ 34, "yellow",100, 1, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/impermeabil-metalizat-c719012p4146515.html",170};
	Coat d{ 33, "green", 89, 2, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-roz-la-dou%C4%83-r%C3%A2nduri-de-nasturi-studio-c719012p4425538.html",90 };
	Coat e{ 34, "pink", 59, 3, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-cu-guler-la-baza-g%C3%A2tului-%C5%9Fi-fermoar-c719012p4374513.html" ,50};
	Coat f(35, "blue", 65, 2, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/jachet%C4%83-la-dou%C4%83-r%C3%A2nduri-de-nasturi-c719012p4486065.html",66);
	Coat g{ 35, "red", 110, 1, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-cu-vol%C4%83na%C5%9F-la-m%C3%A2nec%C4%83-c719012p4486063.html" ,70};
	Coat k{ 35, "yellow",39, 1, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-cu-imprimeu-%C5%9Fi-detalii-destr%C4%83mate-c719012p4415039.html" ,90};
	Coat l{ 36, "green", 50, 1, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-cu-rever-%C3%AEntors-c719012p4417013.html",140 };
	Coat m{ 36, "pink", 125, 2, "https://www.zara.com/ro/ro/femei/paltoane-%C8%99i-geci/vizualizeaz%C4%83-tot/palton-lung-c719012p4474028.html" ,100};
	Coat z{ 40,"galben",10,1,"www.google.ro",100 };

	Repository repo;
	Controller ctrl(repo);

	ctrl.add_repo(a);
	ctrl.add_repo(b);
	ctrl.add_repo(c);
	ctrl.add_repo(d);
	ctrl.add_repo(e);
	ctrl.add_repo(f);
	ctrl.add_repo(g);
	ctrl.add_repo(k);
	ctrl.add_repo(l);
	ctrl.add_repo(m);
	ctrl.add_repo(z);


	UI ui(ctrl);
	ui.run();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;

}
