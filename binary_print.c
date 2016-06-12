#include<stdio.h>
#include<stdlib.h>
//hexdump test.bin (linux)

int main (int argc, char*argv[])
{

    int i=0;
    int j=0;
    int fileLen=0;
    int type=0;

    type=3;
    //type = atoi(argv[2]);
    FILE* ptrBinFile;
    //struct rec my_record;
    FILE *write_ptr;

    unsigned char buffer[10];


		//ptrBinFile=fopen(argv[1],"rb");  //wb to write
		//ptrBinFile=fopen("testVbs.vbs","rb");
		
		ptrBinFile=fopen("Show.exe","rb");
		
		if (!ptrBinFile)
		{
			printf("Unable to open file!");
			return -1;
		}

    write_ptr = fopen("test.vbs","wb");  // w for write, b for binary
    if (!write_ptr)
		{
			printf("Unable to open file!");
			return -1;
		}

    //Get file length
    fseek(ptrBinFile, 0, SEEK_END);
    fileLen=ftell(ptrBinFile);
    fseek(ptrBinFile, 0, SEEK_SET);



    //*Allocate memory
    //* buffer=(char *)malloc(fileLen+1);
    //*//Read file contents into buffer
    //* fread(buffer, fileLen, 1, file);
    //* fread(buffer, sizeof(buffer), 1, ptrBinFile); // read 10 bytes to our buffer
    //fread(&my_record,sizeof(struct rec),1,ptr_myfile);
		//fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
		
    fwrite(buffer,sizeof(buffer),1,write_ptr);
    for( i = 0; i<10; i++)
      printf("%u ", buffer[i]); // prints a series of bytes

    printf("\n");

    for( i = 0; i<10; i++)
      printf("%x ", buffer[i]);*/
      
    while (i<fileLen)
    {
      memset(buffer,0,10);
      fread(buffer, sizeof(buffer),1,ptrBinFile);
      for(j=0; j<10;j++)
      {
         if(type==1) //hex
             printf("%x ", buffer[j]);
         else if (type == 2)  //dec
             printf("%d ", buffer[j]);
         else if (type == 3)   //character
             printf("%c ", buffer[j]);
         else if (type == 4)//bin
             printf("%x ", buffer[j]);
      }

      //fwrite(buffer, sizeof(buffer),1, write_ptr);
      printf("\n");
      i+=10;
      //system("pause");
    }


		fclose(ptrBinFile);
		fclose(write_ptr);
		return 0;
}
