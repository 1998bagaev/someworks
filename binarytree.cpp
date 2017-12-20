#include <stdafx.h>
#include <iostream>
using namespace std;
struct Tree
{
    Tree *l,*r; //левое и правое поддерево
    int x; //Некие данные
};
//==============

/*Функция добавления звена в дерево*/
void Add(int x,Tree **Node) //В функцию принимается указатель на элемент данных и указатель на указатель на структуру
{
    if ((*Node==NULL))  //Если дерева не существует
    {
                 (*Node)=new Tree; //Выделяем для него память
     (*Node)->l=(*Node)->r=NULL; //И очищаем пути дальнейшего роста
     (*Node)->x=x; //Записываем информацию в узел на выделенное место
    }
    else //Если дерево уже есть
                //Сравниваем корень дерева с вводимым элементом 
    if (x<(*Node)->l) Add(x,&(*Node)->l); //Если он меньше, пытаемся записать влево
    else Add(x,&(*Node)->r); //Если больше, пытаемся вправо    
}

/*обход в прямом порядке: корень- левое - правое*/
 void ShowP(Tree *Node)
{
    if (Node==NULL)    return;    //Если дерева нет, выходим
    
    cout<<Node->x<<endl; //Посетили узел
    ShowP(Node->l); //Обошли левое поддерево    
    ShowP(Node->r); //Обошли правое поддерево    
}

/*обход в симметричном порядке: левое - корень - правое*/
 void ShowS(Tree *Node)
{
    if (Node==NULL)    return;    //Если дерева нет, выходим
    
    ShowS(Node->l); //Обошли левое поддерево  
    cout<<Node->x<<endl; //Посетили узел
    ShowS(Node->r); //Обошли правое поддерево    
}

/*обход в обратном порядке: левое - правое - корень*/
 void ShowO(Tree *Node)
{
    if (Node==NULL)    return;    //Если дерева нет, выходим
    
    ShowO(Node->l); //Обошли левое поддерево  
    ShowO(Node->r); //Обошли правое поддерево  
    cout<<Node->x<<endl; //Посетили узел  
}

int main()
{
    int x; //Некоторые данные
    Tree *MyTree=NULL; //Указатель на нашу структуру. Инициализируем во избежание ошибок

  for (int i=0;i<10;i++) //В дереве будет 10 узлов
  {
      cout<<"X = "; cin>>x; //Ввели X с клавиатуры
      Add(x,&MyTree); //Добавили X в дерево
  }

  ShowP(MyTree); //Обошли дерево и показали его звенья в прямом порядке
  system("pause");
  return 0;
}
