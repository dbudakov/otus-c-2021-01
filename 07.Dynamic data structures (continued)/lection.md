# Динамические структуры данных

Динамические структуры применяются в случаях когда размер выходного массива неопределен

Виды:

- Списки
  - односвязный
  - двусвязный(двунаправленный)
  - циклические списки(кольца)

- Деревья
- Графы


Узел - содержит ссылки на другие узлы

```c
// не масшабируется на кол-во атрибутов
struct Node {
  char word[N];
  int count;
  Node *next;
}

// масштабируемая по кол-ву атрибутов
struct data{
  char word[N];
  int count;
  ...
} Data;

struct Node {
  Data p_data;
  Node *next;
};

// Задание имени типа структуры
typedef Node *PNode; 

// инициализация структуры
PNode Head = NULL;
```

(!)Для работы со списком необходимо знать адрес первого элемента(головы списка)

## Операции со списками

- Создать новый узел
- Добавить узел
  - В начало списка [11:00]
  - После заданного узла
  - В конец списка
  - До заданного узла
- Отобразить/обработать список
- Поиск узла в списке
- Удалить узел


```c
//Создание узла
Pnode CreateNode (входные параметры)
{
  PNode NewNode = (Node *)malloc(sizeof(Node));
  ... // Присвоение данных
  NewNode->next = NULL;
  return NewNode;
}

// Добавление узла в начало списка
void AddFirst(PNode &Head, PNode NewNode){
  NewNode->next = Head;
  Head = NewNode;
}

// Добавление узла после заданного
void AddAfter(PNode p, PNode NewNode) {
  NewNode -> next = p->next;
  p->next = NewNode;
}

// Добавление в конец
void AddLast(PNode &Head, PNode NewNode){
  PNode q = Head;
  if (Head == NULL) {         // Добавление в пустой список
    AddFirst(Head, NewNode);
    return;}
  while(q->next) q = q->next; // Поиск последнего узла
  AddAfter(q, NewNode)        // Добавление последнего узла
}

// Добавление узла перед заданным
void AddBefore(PNode &Head, PNode p, PNode NewNode){
  PNode q = Head;
  if (Head == NULL) {
    AddFirst (Head, NewNode);
    return;}
  while (q && q->next != p) q = q->next; // Поиск узла перед p
  if(q) AddAfter(q, NewNode);
}

// Добавление узла перед заданным, подмена данных при сохранении адресов
// Не использовать, если p = NULL;
void AddBefore2(PNode p, PNode NewNode){
  Node temp;
  temp = *p; *p = *NewNode; 
  *NewNode = temp; p->next = NewNode;
}

// Отобразить, обработать список
PNode q = Head;
while (q) {
  ...           // отображение или обработка
  q = q->next;
}

// Поиск узла в списке по условию
PNode Find(PNode Head, данные поиска){
  PNode q = Head;
  while(q && условие сравнения данных){
    q = q>next;
  }
  return q;
}

// Удаление узла
void DeleteNode(PNode &Head, PNode p){
  PNode q = Head;
  if (p == Head);     // удаление первого узла
    Head = p->next;
  else {
    while (q && q->next != p) q = q->next; // Поиск предыдущего узла
    if(q == NULL) return;
    q->next = p->next; 
  }
  free(p);
}
```

## Двусвязные списки

```c
struct Node{
  char word[N];
  int count;
  Node *next;
  Node *prev;
}
typedef Node *PNode;
PNode Head = NULL; Pnode Tail = NULL;
```

### Реализация очереди через списки

```c
// Структура узла
struct Node{  
  int data;
  Node* next;
}
typedef Node* PNode;

// тип данных "очередь"
Struct Queue {
  Pnode Head, Tail;
}

// Добавление элемента
void PushTail(Queue &Q, int x){
  PNode NewNode = (Node *)malloc(sizeof(Node));
  NewNode->data = x;
  NewNode->next = NULL;
  if(Q.Tail)
    Q.Tail->next = NewNode;
  Q.Tail = NewNode;
  if(Q.Head == NULL)
    Q.Head = Q.Tail;
}

// Выборка элемента
int Pop(Queue &Q){
  PNode top = Q.Head;
  int x;
  if (top == NULL)    // очередь пуста 
    return -1; 
  x = top->data;
  Q.Head = top->next;
  if(Q.Head == NULL)  // очередь стала пустой
    Q.Tail = NULL;
  free(top);
  return x;
}
```

### Реализация стека через список

```c
struct Node {
  int data;
  Node* next;
}
tupedef Node* PNode;

// Добавление элемента
void Push(PNode &Head, intx){
  PNode NewNode = (Node*)malloc(sizeof(Node));
  NewNode->data = x;
  NewNode->next = Head;
  Head = NewNode;
}

// Выборка элемента
int Pop (PNode &Head){
  PNode q = Head;
  int x;
  if(Head == NULL)  // стек пуст
    return -1;
  x = Head->data;
  Head = Head->next;
  free(q);
  return x;
}
```

## Деревья

Дерево - структура данных, состоящая из узлов и соединяющих направленных ребер(дуг), причем в каждый узел(кроме корневого) ведет одна дуга. Узлы из которых ничего не выходит, называются **листья**

Область применения:

- Поиск данных(двоичное дерево в базах данных)
- Сортировка данных
- Вычисление арифметических выражений
- Кодирование информации


```c
struct Node{
  данные;
  Node *left, *right;
}
typedef Node *PNode; 
```

### Двоичное(бинарное) дерево

Дерево, в котором каждый узел имеет не более двух подчиненных узлов("сыновей")
Слева от каждого узла находятся узлы с меньшими характеристиками, а с права - с большими

### Поиск по дереву

```c
PNode Search(PNode Tree, int x) {
  if (!Tree) return NULL;
  if (x == Tree->data) return Tree; // Элемент найден
  if (x < Tree-> data)
    return Search(Tree->left, x);
  else
    return Search(Tree->right, x);
}
```

### Обход дерева

- Инфиксная форма - слева на право(ЛКП - левый-корень-правый)
- Префиксная форма - сверху вниз(КЛП - корень-левый-правый)
- Посфиксная форма - снизу вверх(ЛПК - левый-правый-корень)

```c
// LKP
void LKP(PNode Tree){
  if (!Tree) return;
  LKP (Tree->left);
  printf("%d", Tree->data);
  LKP(Tree->right);
}
```
