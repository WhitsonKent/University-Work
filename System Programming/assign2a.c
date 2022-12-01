#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//takes strings and makes them usable colors

int main(int argc,char *argv[]){
  int fd;
  fd = open(argv[1],O_CREAT|O_WRONLY,0755);
  char palette[5][3];//color palette, contains the 5 colors entered in argument line
  //CREATE PPM HEADER
	char header[17] = "P6\n1000 1000\n255\n";
	write(fd, &header, sizeof(header));

	for (int i = 0; i < 5; i++)
	{
    if(strcmp(argv[i+2],"red")==0){
      palette[i][0]= 255;
      palette[i][1]= 0;
      palette[i][2]= 0;
    }
    else if(strcmp(argv[i+2],"green")==0){

    }
    else if(strcmp(argv[i+2],"blue")==0){
    }
    else if(strcmp(argv[i+2],"yellow")==0){

    }
    else if(strcmp(argv[i+2],"magenta")==0){

    }
    else if(strcmp(argv[i+2],"orange")==0){

    }
    else if(strcmp(argv[i+2],"ocean")==0){

    }
    else if(strcmp(argv[i+2],"violet")==0){

    }
    else if(strcmp(argv[i+2],"cyan")==0){

    }
    else if(strcmp(argv[i+2],"white")==0){

    }
    else
    {//default to black

    }
	}
  //child 1
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
        if (j < 500)
          write(fd, palette[1], 3);
        else
          write(fd, palette[2], 3);
		exit(0);
	}
	wait(NULL);
  //child 2
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
      if (j < 500)
        write(fd, palette[1], 3);
      else
        write(fd, palette[2], 3);
		exit(0);
	}
	wait(NULL);
  //child 3
	if (fork() == 0)
	{
		for ( int i = 0; i < 50; i++ )
			for ( int j = 0; j < 1000; j++ )
        if (j < 500)
          write(fd, palette[1], 3);
        else
          write(fd, palette[2], 3);
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
      if (j < 500)
        write(fd, palette[3], 3);
      else
        write(fd, palette[4], 3);
		exit(0);
	}
	wait(NULL);

  //child 9
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
      if (j < 500)
        write(fd, palette[3], 3);
      else
        write(fd, palette[4], 3);
		exit(0);
	}
	wait(NULL);
  //child 10
	if (fork() == 0)
	{
		for ( int i = 0; i < 100; i++ )
			for ( int j = 0; j < 1000; j++ )
      if (j < 500)
        write(fd, palette[3], 3);
      else
        write(fd, palette[4], 3);
		exit(0);
	}
	wait(NULL);
	close(fd);
}
