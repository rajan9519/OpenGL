#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

// defining global variables(no need to pass in every function)
const int N=500;
int vec[N],compares,exchanges;
std::string sortName;

void initGL();
void display();
void visual(int* arr);
void drawBitmapString(float x,float y,std::string s);

#include"sort.h"

int main(int argc,char** argv){

  // Generating random array within the range of N
  srand((unsigned)time(0));
  for(int i=0;i<N;i++){
    vec[i] = (rand()%N);
  }

  glutInit(&argc,argv);// initializing glut
  glutInitWindowSize(1000,600);// size of the window
  glutCreateWindow("Sorting Visualization");// name of window
  glutInitWindowPosition(50,50); // your screen cordinate at which window will appear
  glutDisplayFunc(display); // call back function
  initGL(); // initializing GL
  gluOrtho2D(0,1000,0,600); // transforming clipping area to Viewport area
  glutMainLoop(); // infinite processing loop
  return 0;
}

void initGL(){
  glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void display(){
  visual(vec);
  int arr[N];

  sortName = "selection sort";
  compares = 0,exchanges = 0;
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  selectionSort sel(arr,N);
  sleep(1);

  compares = 0,exchanges = 0;
  sortName = "shell sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  shellSort shell(arr,N);
  sleep(1);

  compares = 0,exchanges = 0;
  sortName = "quick sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  quickSort quick(arr,N);
  sleep(1);

  compares = 0,exchanges = 0;
  sortName = "merge sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  mergeSort merge(arr,N);
  sleep(1);
}


void visual(int* arr){
  glClear(GL_COLOR_BUFFER_BIT); // sets the previous background with the current background
  drawBitmapString(400,570,sortName);
  drawBitmapString(400,550,"Number of Compares:"+std::to_string(compares));
  drawBitmapString(400,530,"Number of Exchanges:"+std::to_string(exchanges));
  glColor3f(1.0f,0.0f,0.0f); //red
  // drawing bars on the screen by diagonal coordinates
  for(int i=0;i<N;i++){
    glRecti(2*i,0,2*i+1,arr[i]);
  }
  glFlush();
  usleep(150);
}

void drawBitmapString(float x,float y,std::string s)
{
  glColor3f(1.0f,1.0f,1.0f); // sets color of the text
  glRasterPos2f(x, y);// screen coordinate at which text will appear
  int length = s.size();
  // writing charater by charater on the screen
  for(int i=0;i<length;i++)
  {
     glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, s[i]);
  }
}
