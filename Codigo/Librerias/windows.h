#include "global.h"
#include "time.h"

// ***** SECCION DEL SISTEMA *****
int delete_trash(char* path){
    if(strcmp(path,"C://Windows/System32/netsh interface show interface")==0){
        return 1;//metodo netlist
    }
    if(strcmp(path,"C://Windows/System32/wbem/WMIC computersystem get username")==0){
        return 2;
    }

}

char** tuberia(char* path, int *laps){
    FILE *pipe;
    char buf[128],**retorno=(char**)malloc(50),**username=(char**)malloc(1);
    username[0]=(char*)malloc(128);
    int i=0,j=0,posicion;
    pipe = _popen(path,"r");
    char backslash = '\\';
    if(!pipe){
        printf("Tuberia no accedida.\n");
    }else{
        fgets (buf, 128,pipe);
        if(delete_trash(path)==1){//Elimina la cadena basura que no se necesita de la cadena del comando netsh
            for(int k =0 ; k<2; k++){
                fgets (buf, 128,pipe);
            }

        }
        while(fgets (buf, 128,pipe)){
            if(buf[0]!=' '){
                if(delete_trash(path)==2){
                        if(strstr(buf, "\\")){
                            posicion = strlen(buf) - strlen(strstr(buf, "\\"));
                        for(i=posicion+1; i<strlen(buf); i++){
                            username[0][j] = buf[i];
                            j++;
                        }
                        username[0][j] = '\0';
                        return username;
                    }
                }
                retorno[i]=(char*)malloc(128);
                strcpy(retorno[i],buf);
                i++;
            }
        }
    }
    *laps=i-1;
    _pclose(pipe);
    return retorno;
}


char* kernel_version(){

    char **version= (char**) malloc(2);
    version[0]=(char*) malloc(128);
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get caption,Version");
    int size=0;
    strcpy(version[0],tuberia(command,&size)[0]);
    printf("%s",version[0]);
    return version[0];

}

int running_processes(){

    char **procesos=(char**)malloc(1);
    procesos[0]=(char*)malloc(128);
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get NumberOfProcesses");
    int size=0;
    strcpy(procesos[0],tuberia(command,&size)[0]);
    printf("%s",procesos[0]);
    return atoi(procesos[0]);

}

char* current_user(){

    char **user = (char**)malloc(1);
    user[0]=(char*)malloc(128);
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC computersystem get username");
    int size=0;
    strcpy(user[0],tuberia(command,&size)[0]);
    printf("%s",user[0]);
    return user[0];

}

char* obtener_hora(){
    time_t t;
    struct tm *tm;
    char* fechahora= (char*)malloc(100);
    t=time(NULL);
    tm=localtime(&t);
    strftime(fechahora, 100, "%d/%m/%Y %H:%M", tm);
    return fechahora;
}

char* date_time(){
    char* fechayhora= (char*)malloc(100);
    strcpy(fechayhora,obtener_hora());
    printf ("%s\n", fechayhora);
    return fechayhora;
}

void uptime(){
    /*
    char *horaactual=(char*)malloc(100);;
    strcpy(horaactual,obtener_hora());
    printf(horaactual);
    */
}

// ***** SECCION DE MEMORIA *****
float mem_total(){
    char memo[20],command[128];
    float mem;
    int i;
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get totalvisiblememorysize");
    int size=0;
    mem=(float)atoll(tuberia(command,&size)[0]);
    for (i=0; i<2; ++i){
        mem=mem/1024;
    }
    printf("%.2fGB",mem);
    return mem;
}

float mem_total_free(){
    char memo[20],command[128];
    float mem;
    int i,size=0;
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get freephysicalmemory");
    mem=(float)atoll(tuberia(command,&size)[0]);
    for (i=0; i<2; ++i){
        mem=mem/1024;
    }
    printf("%.2fGB",mem);
    return mem;
}

float mem_swap(){
    char memo[20],command[128];
    float memvir,mem;
    int i,size=0;
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get totalvirtualmemorysize");
    memvir=(float)atoll(tuberia(command,&size)[0]);
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get totalvisiblememorysize");
    mem=(float)atoll(tuberia(command,&size)[0]);
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
    int i,size=0;
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get freevirtualmemory");
    memvir=(float)atoll(tuberia(command,&size)[0]);
    strcpy(command,"C://Windows/System32/wbem/WMIC OS get freephysicalmemory");
    mem=(float)atoll(tuberia(command,&size)[0]);
    memvir= memvir - mem;
    for (i=0; i<2; ++i){
        memvir=memvir/1024;
    }
    printf("%.2fGB",memvir);
    return memvir;
}

// ***** SECCION DE DISCO *****

char** disk_list(){
    char **disks;
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC diskdrive get caption");
    int i=0,size,aux;
    tuberia(command,&size);
    disks=(char**)malloc(size);
    for(i=0; i<size;i++){
        disks[i]=(char*)malloc(128);
    }
    disks=tuberia(command,&aux);
    for(i=0; i<size;i++){
        printf(disks[i]);
    }
    return disks;

}

float* disk_space(){
    char **disks,**space;
    float *spacevalue,*disksvalue;
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC logicaldisk get size");
    int i=0,size,aux;
    tuberia(command,&size);
    disks=(char**)malloc(size);
    space=(char**)malloc(size);
    disksvalue=(float*)malloc(size);
    spacevalue=(float*)malloc(size);
    for(i=0; i<size;i++){
        disks[i]=(char*)malloc(128);
        space[i]=(char*)malloc(128);
    }
    disks=tuberia(command,&aux);
    strcpy(command,"C://Windows/System32/wbem/WMIC logicaldisk get freespace");
    space=tuberia(command,&aux);
    for(i=0; i<size;i++){
        printf("sp: %s",disks[i]);
    }

    for(i=0; i<size;i++){
        spacevalue[i]=atoll(space[i]);
        disksvalue[i]=atoll(disks[i]);
        spacevalue[i]=disksvalue[i]-spacevalue[i];
        free(disks[i]);
        free(space[i]);
        for(int j= 0; j<3;j++){
            spacevalue[i]=spacevalue[i]/1024;
        }
        printf("espacio usado: %2f\n",spacevalue[i]);
    }
    return spacevalue;
}


char** partitions_list(){
    char **partitions;
    char command[128];
    strcpy(command,"C://Windows/System32/wbem/WMIC volume get caption");
    int i=0,size,aux;
    tuberia(command,&size);
    partitions=(char**)malloc(size);
    for(i=0; i<size;i++){
        partitions[i]=(char*)malloc(128);
    }
    partitions=tuberia(command,&aux);
    for(i=0; i<size;i++){
        printf(partitions[i]);
    }
    return partitions;
}

// ***** SECCION DE REDES *****
char** net_list(){
    char **netlist;
    char command[128];
    strcpy(command,"C://Windows/System32/netsh interface show interface");
    int i=0,size,aux;
    tuberia(command,&size);
    netlist=(char**)malloc(size);
    for(i=0; i<size;i++){
        netlist[i]=(char*)malloc(128);
    }
    netlist=tuberia(command,&aux);
    for(i=0; i<size;i++){
        printf(netlist[i]);
    }
    return netlist;
}

char** net_list_ip(){
    char **netlist, **consulta, **ipv6, *token, *linea, argumentos[5][100], name[100];
    char command[128];
    strcpy(command,"C://Windows/System32/netsh interface ipv4 show ipaddresses");
    int i=0,size,cantidad_interfaces=0,interfaz = 0;
    consulta = tuberia(command,&size);
    while(consulta[i]){
        if(strstr(consulta[i],"Interfaz")){
            cantidad_interfaces++;
        }//if
        i++;
    }//while
    netlist = (char**)malloc(cantidad_interfaces);
    i=0;
    while(consulta[i]){
        if(strstr(consulta[i],"Interfaz")){
            strcpy(name,consulta[i]);
            linea = (char*)malloc(strlen(consulta[i+4]));
            strcpy(linea,consulta[i+4]);
            token = strtok(linea," ");
            int x = 0;
            while(token != NULL){
                strcpy(argumentos[x],token);
                token = strtok(NULL," ");
                x++;
            }//while

            token = strtok(name,":\n");
            token = strtok(NULL,":\n");
            strcpy(name,token);

            if(strstr(argumentos[1],"Preferido")){
                strcat(name,"  ");
                strcat(name,argumentos[4]);
            }else if(strstr(argumentos[1],"Tentativo")){
                strcat(name,"  ");
                strcat(name,"Sin IP");
            }
            netlist[interfaz] = (char*)malloc(100);
            strcpy(netlist[interfaz],name);
            interfaz++;
        }//if
        i++;
    }//while
    return netlist;
}//net_list_ip