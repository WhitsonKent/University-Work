#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void stringToColor(char *colorName, char *color);//takes strings and makes them usable colors

int main(int argc,char *argv[]){
  int fd;
  fd = open(argv[1],O_CREAT|O_WRONLY,0755);

  //CREATE PPM HEADER
	char header[17] = "P6\n1000 1000\n255\n";
	write(fd, &header, sizeof(header));

	char palette[5][3];//color palette, contains colors entered in argument line
	for (int i = 0; i < 5; i++)
	{
		stringToColor(argv[i+2],palette[i]);
	}
	int pid;
	int status;
  //child 1
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
				write(fd, (j < 500) ? palette[1] : palette[2], 3);
		exit(0);
	}
	wait(NULL);
  //child 2
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
				write(fd, (j < 500) ? palette[1] : palette[2], 3);
		exit(0);
	}
	wait(NULL);
  //child 3
	if (fork() == 0)
	{
		for ( int i = 0; i < 50; i++ )
			for ( int j = 0; j < 1000; j++ )
				write(fd, (j < 500) ? palette[1] : palette[2], 3);
		for( int i = 1; i < 51; i++ )
		{
			for ( int j = 0; j < 500 - i; j++ )
				write(fd, palette[1], 3);
			for ( int l = 0; l < 2*i; l++ )
				write(fd, palette[0], 3);
			for ( int j = 0; j < 500 - i; j++ )
				write(fd, palette[2], 3);
		}
		exit(0);
	}
	wait(NULL);
  //child 4
	if (fork() == 0)
	{
		for( int i = 1; i < 101; i++ )
		{
			for ( int j = 0; j < 500 - (i+50); j++ )
				write(fd, palette[1], 3);
			for ( int l = 0; l < 2*(i+50); l++ )
				write(fd, palette[0], 3);
			for ( int j = 0; j < 500 - (i+50); j++ )
				write(fd, palette[2], 3);
		}
		exit(0);
	}
	wait(NULL);
  //child 5
	if (fork() == 0)
	{
		for( int i = 1; i < 101; i++ )
		{
			for ( int j = 0; j < 500 - (i+150); j++ )
				write(fd, palette[1], 3);
			for ( int l = 0; l < 2*(i+150); l++ )
				write(fd, palette[0], 3);
			for ( int j = 0; j < 500 - (i+150); j++ )
				write(fd, palette[2], 3);
		}
		exit(0);
	}
	wait(NULL);
  //child 6
	if (fork() == 0)
	{
		for( int i = 101; i > 1; i-- )
		{
			for ( int j = 0; j < 500 - (i+150); j++ )
				write(fd, palette[3], 3);
			for ( int l = 0; l < 2*(i+150); l++ )
				write(fd, palette[0], 3);
			for ( int j = 0; j < 500 - (i+150); j++ )
				write(fd, palette[4], 3);
		}
		exit(0);
	}
	wait(NULL);
  //child 7
	if (fork() == 0)
	{
		for( int i = 101; i > 1; i-- )
		{
			for ( int j = 0; j < 500 - (i+50); j++ )
				write(fd, palette[3], 3);
			for ( int l = 0; l < 2*(i+50); l++ )
				write(fd, palette[0], 3);
			for ( int j = 0; j < 500 - (i+50); j++ )
				write(fd, palette[4], 3);
		}
		exit(0);
	}
	wait(NULL);
  //child 8
	if (fork() == 0)
	{
		for( int i = 51; i > 1; i-- )
		{
			for ( int j = 0; j < 500 - (i); j++ )
				write(fd, palette[3], 3);
			for ( int l = 0; l < 2*(i); l++ )
				write(fd, palette[0], 3);
			for ( int j = 0; j < 500 - (i); j++ )
				write(fd, palette[4], 3);
		}
		for ( int i = 0; i < 50; i++ )
			for ( int j = 0; j < 1000; j++ )
				write(fd, (j < 500) ? palette[3] : palette[4], 3);
		exit(0);
	}
	wait(NULL);

  //child 9
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
				write(fd, (j < 500) ? palette[3] : palette[4], 3);
		exit(0);
	}
	wait(NULL);
  //child 10
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
				write(fd, (j < 500) ? palette[3] : palette[4], 3);
		exit(0);
	}
	wait(NULL);

	close(fd);
}

void stringToColor(char *colorName, char *color)
{
	if(strcmp(colorName,"red")==0){
    color[0]= 255;
    color[1]= 0;
    color[2]= 0;
  }
  else if(strcmp(colorName,"green")==0){
    color[0]= 0;
    color[1]= 255;
    color[2]= 0;
  }
  else if(strcmp(colorName,"blue")==0){
    color[0]= 0;
    color[1]= 0;
    color[2]= 255;
  }
  else if(strcmp(colorName,"yellow")==0){
    color[0]= 255;
    color[1]= 255;
    color[2]= 0;
  }
  else if(strcmp(colorName,"magenta")==0){
    color[0]= 255;
    color[1]= 0;
    color[2]= 255;
  }
  else if(strcmp(colorName,"orange")==0){
    color[0]= 255;
    color[1]= 165;
    color[2]= 0;
  }
  else if(strcmp(colorName,"ocean")==0){
    color[0]= 135;
    color[1]= 206;
    color[2]= 250;
  }
  else if(strcmp(colorName,"violet")==0){
    color[0]= 128;
    color[1]= 0;
    color[2]= 128;
  }
  else if(strcmp(colorName,"cyan")==0){
    color[0]= 0;
    color[1]= 255;
    color[2]= 255;
  }
  else if(strcmp(colorName,"white")==0){
    color[0]= 128;
    color[1]= 0;
    color[2]= 128;
  }
  else
  {//default to black
    color[0]= 0;
    color[1]= 0;
    color[2]= 0;
  }
}
