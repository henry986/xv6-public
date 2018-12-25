#include "types.h"
#include "stat.h"
#include "user.h"

static void
getc(int fd, char ** buffer){
	int  i = 0;
	char buf[256];	// 讀進buffer
	while(read(fd, &buf[i], 1)){
		if((buf[i] == '\n' || buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\r' || buf[i] == '\v' || buf[i] == '\f')){
			break;
		}
		else{
			i++;
		}
	}
	buf[i] = '\0';
	*(buffer) = buf;
}

int atoi_decimal(char *buf){	
	int res = 0;  
	int sign = 1;  
	int i = 0;  
  
	if (buf[0] == '-'){	// 如果是負數，就更新sign
		sign = -1;  
		i++;  
	}
      	for (; buf[i] != '\0'; i++){
    		if(buf[i] - '0' < 0 || buf[i] - '0' > 9)  // 如果不是數字就break
    			break ;
        res = res*10 + buf[i] - '0';
    	}
	return sign*res;
}

void scanf(int fd, char * fmt, ...){
	int i = 0;
	char c;
	char * buf = "";	// 暫時保留input
	int count_args = 1;
	uint var = *((uint*)(void*)&fmt + count_args);
	count_args++;
	for(i = 0; fmt[i]; i++){
		c = fmt[i] & 0xff;
		if(c=='c'){
			getc(fd, &buf);
			*(char *)(var) = buf[0];	
			buf = "";
			var = *((uint*)(void*)&fmt + count_args);
			count_args++;
		}
				
		if(c=='d'){
			getc(fd,&buf);
			*(int *)(var) = atoi_decimal(buf);	
			buf = "";
			var = *((uint*)(void*)&fmt + count_args);
			count_args++;
		}

		if(c=='s'){
			getc(fd, &buf);
			strcpy((char *)var, buf); 		
			var = *((uint*)(void*)&fmt + count_args);
			count_args++;
			buf = "";	
		}
			
	}
	
}
