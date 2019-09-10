
float b_1=0.5050;
float b_1b=0.5578;
float b_2=0.6514;
float b_3=0.7222;
float b_4=0.7825;
float b_5=0.8126;
float b_6=0.8434;
float b_7=0.8693;
float b_8=0.8910;
float b_9=0.9092;
float b_10=0.9222;
float b_11=0.9319;
float b_12=0.9403;
float b_13=0.9477;
float b_14=0.9544;
float b_15=0.9602;
float b_16=0.9653;


float a_1=1.2599;
float a_1b=1.1696;
float a_2=1.0000;
float a_3=0.8618;
float a_4=0.7562;
float a_5=0.6670;
float a_6=0.5933;
float a_7=0.5282;
float a_8=0.4701;
float a_9=0.4187;
float a_10=0.3798;
float a_11=0.3497;
float a_12=0.3223;
float a_13=0.2971;
float a_14=0.2737;
float a_15=0.2523;
float a_16=0.2327;

float t12_1=4.00;
float t12_1b=5.00;
float t12_2=8.00;
float t12_3=12.50;
float t12_4=18.50;
float t12_5=27.00;
float t12_6=38.30;
float t12_7=54.30;
float t12_8=77.00;
float t12_9=109.00;
float t12_10=146.00;
float t12_11=187.00;
float t12_12=239.00;
float t12_13=305.00;
float t12_14=390.00;
float t12_15=498.00;
float t12_16=635.00;

 
float Piig=0;      //Einatemdruck
float airp=1.01325;//Luftdruck
float Pamb=airp;//Umgebungsdruck
float PsH2o=0.063; //Sättigungsdampfdruck von Wasser
float fig=78.08;   //Anteil des Inertgases im Atemgemisch in %
float PigtE=0; //Inertgasdruck im Gewebe nach der Expositionszeit tE
float Nz=999;
float Nz_G=0;

float Pigt0_1=(airp-PsH2o)*(fig/100);
float Pigt0_1b=(airp-PsH2o)*(fig/100);
float Pigt0_2=(airp-PsH2o)*(fig/100);
float Pigt0_3=(airp-PsH2o)*(fig/100);
float Pigt0_4=(airp-PsH2o)*(fig/100);
float Pigt0_5=(airp-PsH2o)*(fig/100);
float Pigt0_6=(airp-PsH2o)*(fig/100);
float Pigt0_7=(airp-PsH2o)*(fig/100);
float Pigt0_8=(airp-PsH2o)*(fig/100);
float Pigt0_9=(airp-PsH2o)*(fig/100);
float Pigt0_10=(airp-PsH2o)*(fig/100);
float Pigt0_11=(airp-PsH2o)*(fig/100);
float Pigt0_12=(airp-PsH2o)*(fig/100);
float Pigt0_13=(airp-PsH2o)*(fig/100);
float Pigt0_14=(airp-PsH2o)*(fig/100);
float Pigt0_15=(airp-PsH2o)*(fig/100);
float Pigt0_16=(airp-PsH2o)*(fig/100);
 
float Pigt0[]={ Pigt0_1 , Pigt0_1b , Pigt0_2 , Pigt0_3 , Pigt0_4 , Pigt0_5 , Pigt0_6 , Pigt0_7 , Pigt0_8 , Pigt0_9 , Pigt0_10 , Pigt0_11 , Pigt0_12 , Pigt0_13 , Pigt0_14 , Pigt0_15 , Pigt0_16 };  //Inertgasdruck im Gewebe zu beginn der Expositionszeit tE
float tE=0;        //Einwirkzeit in min
float t12[]={ t12_1 , t12_1b , t12_2 , t12_3 , t12_4 , t12_5 , t12_6 , t12_7 , t12_8 , t12_9 , t12_10 , t12_11 , t12_12 , t12_13 , t12_14 , t12_15 , t12_16};      //Halbwärtszeit des Gewebes  
int   numGewebe=17;
float Pambtol=0;   //Von einem Gewebe noch Tolerierter Druck, bei dem noch keine Gasbasen auftreten
float Pambtolmax=0;//Das Gewebe mit dem höchsten noch Tolerierter Druck, bei dem noch keine Gasbasen auftreten
float x=0; //Wert bei der Nullzeitberechnung
float y=0; //Wert bei der 2 Dekoberechnung
float a[]={ a_1 , a_1b , a_2 , a_3 , a_4 , a_5 , a_6 , a_7 , a_8 , a_9 , a_10 , a_11 , a_12 , a_13 , a_14 , a_15 , a_16}; //Gewebefaktoren
float b[]={ b_1 , b_1b , b_2 , b_3 , b_4 , b_5 , b_6 , b_7 , b_8 , b_9 , b_10 , b_11 , b_12 , b_13 , b_14 , b_15 , b_16}; //Gewebefaktoren 


void setup() {
  Serial.begin(9600);
  pinMode(A5,INPUT);
}
   

void loop() { 
  
   Pamb=(analogRead(A5)/400)+airp;
   Dekogleichung1();
   Dekogleichung2_3();
   Nullzeitberechnung();
   Serial.print("Pamb:");
   Serial.println(Pamb);
   Serial.print("Tauchzeit:");
   Serial.println(tE);
   
      
   tE=tE+3;
   
   delay(2000);
}
void DekodatenAuslesen(){
//Pamb=digitalRead(Drucksensor);
}

void Dekogleichung1(){  
  Piig=(Pamb-PsH2o)*(fig/100);  //Funktioniert
}

void Dekogleichung2_3(){
  for(int i=0;i<numGewebe;i++){
   
    
  
   PigtE= Pigt0[i] + ((Piig - Pigt0[i]) * (1 - pow(2, (-tE/t12[i])))); //Funktioniert 
     
   
    
     
    Pigt0[i]=PigtE;
  
    
    
    
    //Serial.println(t12[i]);
    Serial.println(i);
    Serial.println(Pigt0[i]);
    
   
  
  Pambtol=(PigtE-a[i])*b[i];
  
  if(Pambtol<Pambtolmax){
    Pambtolmax=Pambtol;
  }
  }
 
}
void Nullzeitberechnung(){
  for(int e=0;e<numGewebe;e++){
  
     x= -1*(((airp/b[e]+a[e]-Pigt0[e])/(Piig-Pigt0[e]))+1);
  
  if(x>0){
    
    Nz_G= -1* log(x)/log(2)*t12[e];

    if(Nz_G<Nz){
      Nz=Nz_G;
      }
    }
    
    
    
    
    }
  
  

 
}
