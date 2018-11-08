#include "global.h"

// ***** SECCION DEL SISTEMA *****
void kernel_version(){

    /*
    FILE *pipe;
    char buf[128];
    pipe = _popen("ver","r"); // escribe el resultado de dir en pipe
    printf("holahola");
    fgets (buf, 128,pipe);
    printf("Version del kernel: %s",buf);
    */
    system("ver");
    system("ver>>.info.txt");
    //char cmd[30]="";
    //strcat(cmd, "C:/Windows/System32/attrib +h ");
    //strcat(cmd, ARCHIVO );
    //system(cmd);
    system("C:/Windows/System32/attrib +h .info.txt");

}

void running_processes(){

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
      
}

void current_user(){

}

void date_time(){

}

void uptime(){

}


// ***** SECCION DE MEMORIA *****
void mem_total(){

}

void mem_total_free(){

}

void mem_swap(){

}

void mem_swap_free(){

}

// ***** SECCION DE DISCO *****

void disk_list(){

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
