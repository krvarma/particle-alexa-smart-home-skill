#define MAX_ARGS 64

int lightPins[] = {
    A5,A4
};

int lightValues[] = {
    255,255
};

int onoffLight(String args){
    int index = args.toInt();
    int value;
    char szArgs[MAX_ARGS];
    int count = sizeof(lightPins) / sizeof(int);
    
    args.toCharArray(szArgs, MAX_ARGS);
    
    sscanf(szArgs, "%d=%d", &index, &value);
    
    Serial.println();
    Serial.print("On/Off");
    Serial.println();
    Serial.print("Arguments: ");
    Serial.print(args);
    Serial.println();
    Serial.print("Index: ");
    Serial.print(index);
    Serial.println();
    Serial.print("Value: ");
    Serial.print(value);
    Serial.println();
    
    if(index >= 0 && index<count){
        analogWrite(lightPins[index], value == 1 ? lightValues[index] : 0);
    }
    
    return lightValues[index];
}

int setPercentage(String args){
    int index;
    int value;
    char szArgs[MAX_ARGS];
    int count = sizeof(lightPins) / sizeof(int);
    
    args.toCharArray(szArgs, MAX_ARGS);
    
    sscanf(szArgs, "%d=%d", &index, &value);
    
    float brightness = ((float)value * 255.0) / 100.0;
    
    if(index >= 0 && index<count){
        lightValues[index] = (int)brightness;
        
        analogWrite(lightPins[index], lightValues[index]);
    }
    
    Serial.println();
    Serial.print("Percentage");
    Serial.println();
    Serial.print("Arguments: ");
    Serial.print(args);
    Serial.println();
    Serial.print("Index: ");
    Serial.print(index);
    Serial.println();
    Serial.print("Value: ");
    Serial.print(value);
    Serial.println();
    Serial.print("Brightness: ");
    Serial.print(brightness);
    Serial.println();
    
    return (int)brightness;
}

void setup() {
    Serial.begin(115200);
    
    int count = sizeof(lightPins) / sizeof(int);
    
    for(int index=0; index<count; ++index){
        pinMode(lightPins[index], OUTPUT);
    }
    
    Particle.function("setvalue", setPercentage);
    Particle.function("onoff", onoffLight);
}

void loop() {
    
}