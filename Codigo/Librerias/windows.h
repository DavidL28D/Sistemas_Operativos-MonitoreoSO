#include "global.h"
#include "time.h"

// ***** SECCION DEL SISTEMA *****

char *tuberia(char* path, int laps){
    FILE *pipe;
    char buf[128],*retorno=(char*)malloc(128);
    int i;
    pipe = _popen(path,"r"); 
    if(!pipe){
        printf("Tuberia no accedida.\n");
    }else{
        for(i=0;i<laps;i++){
            fgets (buf, 128,pipe);
        }
    }
    _pclose(pipe); 
    strcpy(retorno,buf);
    return retorno; 
}

char *kernel_version(){

    char *version= (char*) malloc(128);
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get caption,Version");    
    int i=0;
    strcpy(version,tuberia(command,2));
    printf("%s",version);          
    return version;
    
}

int running_processes(){

    char procesos[128];
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get NumberOfProcesses");    
    strcpy(procesos,tuberia(command,2));
    printf("%s",procesos);  
    return atoi(procesos);

}

char *current_user(){

    char* user = (char*)malloc(128);
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC netlogin get fullname");    
    strcpy(user,tuberia(command,3));
    printf("%s",user);  
    return user;   

}


char* date_time(){       
    time_t t;
    struct tm *tm;
    char* fechayhora= (char*)malloc(100);
    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y %H:%M", tm);
    printf ("%s\n", fechayhora);   
    return fechayhora;   
}

void uptime(){

}

// ***** SECCION DE MEMORIA *****
float mem_total(){
    char memo[20],command[128];
    float mem;        
    int i;    
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get totalvisiblememorysize");    
    mem=(float)atoll(tuberia(command,2));
    for (i=0; i<2; ++i){
        mem=mem/1024;
    }
    printf("%.2fGB",mem);     
    return mem;
}

float mem_total_free(){
    char memo[20],command[128];
    float mem;        
    int i;    
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get freephysicalmemory");    
    mem=(float)atoll(tuberia(command,2));
    for (i=0; i<2; ++i){
        mem=mem/1024;
    }
    printf("%.2fGB",mem);     
    return mem;
}

float mem_swap(){
    char memo[20],command[128];
    float memvir,mem;        
    int i;    
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get totalvirtualmemorysize");    
    memvir=(float)atoll(tuberia(command,2));
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get totalvisiblememorysize");    
    mem=(float)atoll(tuberia(command,2));
    memvir= memvir - mem;
    for (i=0; i<2; ++i){
        memvir=memvir/1024;
    }
    printf("%.2fGB",memvir);     
    return memvir;
}

float mem_swap_free(){
    char memo[20],command[128];
    float memvir,mem;        
    int i;    
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get freevirtualmemory");    
    memvir=(float)atoll(tuberia(command,2));
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get freephysicalmemory");    
    mem=(float)atoll(tuberia(command,2));
    memvir= memvir - mem;
    for (i=0; i<2; ++i){
        memvir=memvir/1024;
    }
    printf("%.2fGB",memvir);     
    return memvir;
}

// ***** SECCION DE DISCO *****

void disk_list(){

    system("C://Windows/System32/diskpart -listdisk >> .info.txt");
    

}

void disk_space(){
}

void partitions_list(){
}

// ***** SECCION DE REDES *****
void net_list(){
}

void net_list_ip(){
}
