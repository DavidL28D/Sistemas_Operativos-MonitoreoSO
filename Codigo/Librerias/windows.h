#include "global.h"

// ***** SECCION DEL SISTEMA *****
void kernel_version(){

    
    FILE *pipe;
    char buf[256];
    char version[128]="",salto='\n';
    pipe = _popen("C://Windows/System32/wbem/WMIC OS get Version","r"); // escribe el resultado de dir en pipe
    int i=0;
    //system("C://Windows/System32/wbem/WMIC OS get Version");
    if(!pipe){

        printf("Tuberia no accedida.\n");

    }else{
           
        fgets (buf, 128,pipe);
              
        for(i=0; i <= strlen(buf) ;i++){
            if(buf[i] == '\n'){
                buf[i]='\t';
            }
        }

        strcpy(version,buf);  
        fgets (buf, 128,pipe);
        strcat(version,buf);
        printf("%s",version);    

    }
    _pclose(pipe);
    //system("ver");
    //system("ver>>.info.txt");
    //char cmd[30]="";
    //strcat(cmd, "C:/Windows/System32/attrib +h ");
    //strcat(cmd, ARCHIVO );
    //system(cmd);
    //system("C:/Windows/System32/attrib +h .info.txt");

}

void running_processes(){
/*
    //system("C://Windows/System32/TASKLIST >> procesos.txt");
    FILE *pipe,*arc;
    char buf[128];
    int cantProcesos=0;
    printf("Abriendo la Tubería de lectura\n");
    pipe = _popen("C://Windows/System32/TASKLIST","r"); // escribe el resultado de dir en pipe

    if(!pipe){

        printf("Tuberia no accedida.\n");

    }else{

        while (fgets(buf, 128, pipe) != NULL) {

            cantProcesos++;

        }

    }

    printf("Hay %d procesos.",(cantProcesos)-3);
    _pclose(pipe);
    arc=fopen(".info.txt","a");

    if(arc == NULL){

        printf("No Se puede abrir el archivo");

    }else{

        fprintf(arc,"%d",(cantProcesos)-3);

    }
    char cmd[30]="";
    strcat(cmd, "C:/Windows/System32/attrib +h ");
    strcat(cmd, ARCHIVO );
    fclose(arc);
    system(cmd);
    //system("C:/Windows/System32/attrib +h %S",ARCHIVO);
    */
      
}

void current_user(){

}

void date_time(){

}

void uptime(){

}


// ***** SECCION DE MEMORIA *****
void mem_total(){
    //system("C://Windows/System32/wbem/wmic MemoryChip get capacity >> procesos.txt");
    /*FILE *pipe,*arc;
    char buf[128];
    long int memoria=0;
    printf("Abriendo la Tubería de lectura\n");
    pipe = _popen("C://Windows/System32/wbem/wmic MemoryChip get capacity","r"); // escribe el resultado de dir en pipe

    if(!pipe){

        printf("Tuberia no accedida.\n");

    }else{
        printf("memoria: %d\n",memoria/1024);
        fgets(buf, 128, pipe);
        while (fgets(buf, 128, pipe) != NULL) {
            printf("memoria: %s\n",buf);
            if(isdigit(buf[1])){
                printf("memoria: %i\n",atoi(buf));
                memoria += atoi(buf);
            }
        } 
        /*
        fgets(buf, 128, pipe);
        fgets(buf, 128, pipe);
        
            
        

    }

    printf("Hay %d Kb de memoria.",&memoria);
    _pclose(pipe);
    remove(".info.txt");
    arc=fopen(".info.txt","a");

    if(arc == NULL){

        printf("No Se puede abrir el archivo");

    }else{

        fprintf(arc,"%d",&memoria);

    }
    */
}

void mem_total_free(){

}

void mem_swap(){

}

void mem_swap_free(){

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
