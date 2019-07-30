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
float Pamb=1.01325;//Umgebungsdruck
float PsH2o=0.063; //Sättigungsdampfdruck von Wasser
float fig=78.08;   //Anteil des Inertgases im Atemgemisch in %
float PigtE=0;     //Inertgasdruck im Gewebe nach der Expositionszeit tE
float Pigt0=Pamb;  //Inertgasdruck im Gewebe zu beginn der Expositionszeit tE
float tE=0;        //Einwirkzeit in min
float t12[]={ t12_1 , t12_1b , t12_2 , t12_3 , t12_4 , t12_5 , t12_6 , t12_7 , t12_8 , t12_9 , t12_10 , t12_11 , t12_12 , t12_13 , t12_14 , t12_15 , t12_16};      //Halbwärtszeit des Gewebes  
int   numGewebe=17;
float Pambtol=0;   //Von einem Gewebe noch Tolerierter Druck, bei dem noch keine Gasbasen auftreten
float a=0;         //Gewebefaktoren
float b=0;         //Gewebefaktoren

 
 
 

void setup() {
  Serial.begin(9600);
}
   

void loop() {
   
}
void DekodatenAuslesen(){
   
}

void Dekogleichung1(){  
  Piig=(Pamb-PsH2o)*fig;
}

void Dekogleichung2_3(){
  for(int i=0;i<numGewebe;i++){
    PigtE=Pigt0+(Piig-Pigt0)*(1-2^-1*tE/t12[i]);
  }
}
