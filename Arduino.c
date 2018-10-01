#define Possible_Ways 32
#define Initial_CHAR_Convert_to_INT 

setup()
{
	
}

loop()
{
	while(1);
}

RadioInterrupt()
{
	//Recebe Caracter via RF
	char Received_CHAR = radio.read();
	
	int Received_INT = Received_CHAR;

	Angle = ( Received_INT - Initial_CHAR_Convert_to_INT ) * (360 / Possible_Ways);
	
	M1_PWM = 
	M2_PWM =
	M3_PWM = 
	
	SetMotors(M1_PWM,M2_PWM,M3_PWM,);

}

void SetMotors(M1_PWM,M2_PWM,M3_PWM, 
	M1_ENA_level, M1_ENB_level, M2_ENA_level, M2_ENB_level, M3_ENA_level, M3_ENB_level)
{
	analogWrite(M1_PWM_port, M1_PWM);
	analogWrite(M2_PWM_port, M2_PWM);
	analogWrite(M3_PWM_port, M3_PWM);
	digitalWrite(M1_ENA, M1_ENA_level);
	digitalWrite(M1_ENB, M1_ENB_level);
	digitalWrite(M2_ENA, M2_ENA_level);
	digitalWrite(M2_ENB, M2_ENB_level);
	digitalWrite(M3_ENA, M3_ENA_level);
	digitalWrite(M3_ENB, M3_ENB_level);
}
