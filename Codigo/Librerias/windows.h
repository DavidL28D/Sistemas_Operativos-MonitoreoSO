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
    if(strcmp(path,"C://Windows/System32/netsh interface ipv4 show ipaddresses")==0){
        return 3;
    }
    return 0;
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
                if(buf[0]!='\n'){
                    retorno[i]=(char*)malloc(128);
                    strcpy(retorno[i],buf);
                    
                    i++;
                    //printf("i=%d",i);
                }
                
            }
        }
    }
    if(delete_trash(path)==1){
        *laps=i;
    }else if(delete_trash(path)==3){
        *laps=i+1;
    }else{
        *laps=i-1;
    }
    
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

void calculate_uptime(char* inicio, char* actual){
    int annioI,annioA,mesI,mesA,diaI,diaA,horaI,horaA,minutosI,minutosA,j=0;
    char *tokenI,*tokenF,annio[4],mes[2],dia[2],hora[2],minutos[2];
    
    for (int i = 0; i < 4; ++i){
        annio[i]=inicio[i];
    }
    j=0;
    for (int i = 4; i < 6; ++i)    {
        mes[j]=inicio[i];
        j++;
    }
    j=0;
    for (int i = 6; i < 8; ++i)    {
        dia[j]=inicio[i];
        j++;
    }j=0;
    for (int i = 8; i < 10; ++i)    {
        hora[j]=inicio[i];
        j++;
    }j=0;
    for (int i = 10; i < 12; ++i)    {
        minutos[j]=inicio[i];
        j++;
    }
    annioI=atoi(annio);
    mesI=atoi(mes);
    diaI=atoi(dia);
    horaI=atoi(hora);
    minutosI=atoi(minutos);
    j=0;
    tokenF = strtok(actual,"/ :");
    while(tokenF != NULL){
        //printf("%s\n",tokenF);
        
        if(j==0){
            diaA=atoi(tokenF);
            //printf("dia%d\n",diaA);
            j++;
        }else if (j==1){
            mesA=atoi(tokenF);
            j++;
        }else if(j==2){
            annioA=atoi(tokenF);
            j++;
        }else if(j==3){
            horaA=atoi(tokenF);
            j++;
        }else if(j==4){
            minutosA=atoi(tokenF);
            j++;
        }
        tokenF = strtok(NULL,"/ :");
    }

    if(annioA-annioI != 0){
        printf("%d Años",annioA-annioI);
    }
    if(mesA-mesI != 0){
        printf(" %d Meses",mesA-mesI);
    }
    if(diaA-diaI != 0){
        printf(" %d Dias",diaA-diaI);
    }    
    if(horaA-horaI < 0){
        if(minutosA-minutosI < 0){
        printf(" %d Horas",horaA-horaI+23);
        }else{
            printf(" %d Horas",horaA-horaI+24);
        }
    }else{
        if(minutosA-minutosI < 0){
        	printf(" %d Horas",horaA-horaI-1);
        }else{
            printf(" %d Horas",horaA-horaI);
        }
    }   
    if(minutosA-minutosI < 0){
        printf(" %d Minutos",minutosA-minutosI+60);
    }else{
        printf(" %d Minutos",minutosA-minutosI);
    }
    //printf("Año: %d Mes: %d Dia: %d Hora: %d Minutos: %d",annioI,mesI,diaI,horaI,minutosI);

}

void uptime(){
    char **inicio;
    char *horaactual=(char*)malloc(100);
    char command[128];
    int i=0,size,aux;
    strcpy(horaactual,obtener_hora());        
    strcpy(command,"C://Windows/System32/wbem/WMIC os get lastBootUpTime");    
    tuberia(command,&size);
    inicio=(char**)malloc(size);
    for (i = 0; i < size; ++i){
        inicio[i]=(char*)malloc(128);   
        strcpy(inicio[i],tuberia(command,&aux)[i]);
    }    
    printf(inicio[0]);    
    printf(horaactual);    
    calculate_uptime(inicio[0],horaactual);
    //en este punto debo trabajar con las dos cadenas de fecha para convertirlas en el uptime

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
        strcpy(disks[i],tuberia(command,&aux)[i]);
    }

    
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
        strcpy(disks[i],tuberia(command,&aux)[i]);
    }
    
    strcpy(command,"C://Windows/System32/wbem/WMIC logicaldisk get freespace");
    
    for(i=0; i<size;i++){
        strcpy(space[i],tuberia(command,&aux)[i]);
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
        printf("%.2fGB\n",spacevalue[i]);
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
        strcpy(partitions[i],tuberia(command,&aux)[i]);
    }
    
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
    //printf("cantidad: %d",size);
    for(i=0; i<size;i++){
        netlist[i]=(char*)malloc(128);
        strcpy(netlist[i],tuberia(command,&aux)[i]);        
    }
    printf("\n");
    for(i=0; i<size;i++){
        printf(netlist[i]);
    }
    return netlist;
}


char** net_list_ip(){
    char **netlist, **consulta, **ipv6, *token, linea[100], argumentos[5][100], name[100];
    char command[128];
    strcpy(command,"C://Windows/System32/netsh interface ipv4 show ipaddresses");
    int i=0,size,cantidad_interfaces=0,interfaz = 0;
    consulta = tuberia(command,&size);
    
    for(int z = 0; z < size; z++){
        if(strstr(consulta[i],"Interfaz")){
            cantidad_interfaces++;
        }//if
        i++;
    }
    netlist = (char**)malloc(cantidad_interfaces);
    
   for(int z = 0; z < size; z++){
        if(strstr(consulta[z],"Interfaz")){
            strcpy(name,consulta[z]);
            token = strtok(name,":\n");
            token = strtok(NULL,":\n");
            strcpy(name,token);
            strcpy(linea,consulta[z+3]);
             token = strtok(linea," ");
            int x = 0;
            while(token != NULL){
                strcpy(argumentos[x],token);
                token = strtok(NULL," ");
                x++;
            }//while
            if(strstr(argumentos[1],"Preferido")){
                strcat(name,"  ");
                strcat(name,argumentos[4]);
            }else if(strstr(argumentos[1],"Tentativo")){
                strcat(name,"  ");
                strcat(name,"Sin IP");
            }
            netlist[interfaz] = (char*)malloc(100);
            strcpy(netlist[interfaz],name);
            printf("%s\n",netlist[interfaz]);
            interfaz++;
        }//if
    }//for
    return netlist;
}//net_list_ip