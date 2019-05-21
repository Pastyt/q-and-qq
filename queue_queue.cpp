#include <iostream>
using namespace std;
#define QMAX 100
struct queue
{
  int qu[QMAX];
  int rear, frnt;
};
struct Qqueue
{
  queue *qq[QMAX];
  int rear, frnt;
};

int Qisempty(struct Qqueue *q);
int isempty(struct queue *q);
void doin(struct queue *q);

void remvq(Qqueue *Q)
{
  queue *q=Q->qq[Q->frnt];
  printf("Queue 1:\n");
  doin(q);
  for(int i=0;i<Q->rear;i++){
  	Q->qq[i]=Q->qq[i+1];
  }
  (Q->rear)--;
  delete q;
}
void instq(Qqueue *q, queue *x)
{
  if (q->rear < QMAX - 1)
  {
    q->rear++;
    q->qq[q->rear] = x;
  }
  else
    printf("Queue full!\n");
  return;
}
void remvonq(Qqueue *Q)
{
  queue *q = Q->qq[Q->frnt];
  cout << "Number: " << q->qu[q->frnt]<< endl;
  for(int i=0;i<q->rear;i++){
  	q->qu[i]=q->qu[i+1];
  }
  (q->rear)--;
}
void instronq(Qqueue *Q, int x)
{
  queue *q = Q->qq[Q->frnt];
  if (q->rear < QMAX - 1)
  {
    q->rear++;
    q->qu[q->rear] = x;
  }
  else
    printf("Queue full!\n");
  return;
  
}
void Qinit(struct Qqueue *q)
{
  q->frnt = 0;
  q->rear = -1;
  return;
}
void Qdoin(struct Qqueue *qq)
{
  if (Qisempty(qq) == 1)
  {
    printf("qq empty!\n");
    return;
  }
  int i=1;
  while (qq->frnt <= qq->rear) {
  printf("Queue number %d:\n",i);
  doin(qq->qq[qq->frnt]);
  qq->frnt++;
  i++;
  }
  qq->frnt = 0;
  return;
}
int Qisempty(struct Qqueue *q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
void init(struct queue *q)
{
  q->frnt = 0;
  q->rear = -1;
  return;
}
void insert(struct queue *q, int x)
{
  if (q->rear < QMAX - 1)
  {
    q->rear++;
    q->qu[q->rear] = x;
  }
  else
    printf("Queue full!\n");
  return;
}
int isempty(struct queue *q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
void doin(struct queue *q)
{
  if (isempty(q) == 1)
  {
    printf("q empty!\n");
    return;
  }
  printf("Numbers: ");
  while (q->frnt <= q->rear) {
  printf("%d ", q->qu[q->frnt]);
  q->frnt++;
  }
  printf("\n");
  q->frnt = 0;
}

int main()
{
  queue *q = new queue;
  Qqueue *Q = new Qqueue;
  Qinit(Q);
  init(q);
  int a = 1;
  int b;
  cout << "q and qq has been created" << endl
       << endl;
  cout << "1. remvq: show first q and delete from qq" << endl;
  cout << "2. instq: add current q in qq" << endl;
  cout << "3. remvonq: delete first element from first q in qq" << endl;
  cout << "4. instronq: add element in first q from qq" << endl
       << endl;
  cout << "Addicion control functions" << endl;
  cout << "5. create new q (old q losts)" << endl;
  cout << "6. add element in current q" << endl;
  cout << "7. doing queue and show how in works" << endl;
  cout << "0. exit from programm" << endl;
  while (a != 0)
  {
    cin >> a;
    switch (a)
    {
    case 1:
      remvq(Q);
      cout << "Deletion completed\n";
      break;
    case 2:
      instq(Q, q);
      cout << "Add complete\n";
      break;
    case 3:
      remvonq(Q);
      cout << "Deletion completed\n";
      break;
    case 4:
      cout << "Print addicion element" << endl;
      cin >> b;
      instronq(Q, b);
      cout << "Add complete\n";
      break;
    case 5:
      q = new queue;
      init(q);
      cout << "Queue created\n";
      break;
    case 6:
      cout << "Print addicion element" << endl;
      cin >> b;
      insert(q, b);
      cout << "Add complete\n";
      break;
    case 7:
      Qdoin(Q);
      break;
    }
  }
  return 0;
}
