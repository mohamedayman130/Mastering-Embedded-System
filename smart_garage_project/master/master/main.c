
	#include "mcal/inc/spi.h"
	#include "hal/inc/lcd.h"
	#include "hal/inc/keypad.h"
	#include "hal/inc/EEPROM.h"
	uint32_t real_pass=123,counter,enterd_pass,enterd_id;
	uint8_t real_num_of_Cars,car_state,flag,first_five,cut_off;
	uint8_t spi_data,number_of_id,id_counter;
	uint32_t ids[10],idssssssssss[10];///up to 140 element///////////////////////////////////////////////////////////////////////

void power_cut()
{
	uint8_t id_eeprom=eeprom_read(0x00);
	real_num_of_Cars=eeprom_read(0x01);
	PORTD=real_num_of_Cars;
	LCD_WRITE_STRING("power cut off");
	uint8_t id_prog=0,counter=0;
	number_of_id=id_eeprom;
	while(id_eeprom>id_prog)
	{
		//ids[counter++]=eeprom_read_7_bytes(id_prog++*7+20);//this is original program
		idssssssssss[counter]=eeprom_read_7_bytes(id_prog++*7+20);/////////////////////////////////////////////////////////////power cut simulation
		lcd_clear_screen();lcd_write_num(idssssssssss[counter++]);_delay_ms(1000);////power cut simulation
	}
lcd_clear_screen();LCD_WRITE_STRING("enter pass::>> ");SET_CURSOR(1,0);////power cut simulation
}

	uint8_t check_pass()
	{
	uint32_t temp= enterd_id;
	for (uint8_t i=0;i<number_of_id;i++)
	{
	if(ids[i]==temp) return 1;
	}
	return 0;
	}


	int main(void)
	{
	LCD_INIT();
	spi_init();
	eeprom_init();
	KEYBAD_INIT();
	DDRD=0XFF;
	PORTD=real_num_of_Cars;
		
		eeprom_write(0x00,0);//burn this value in this location one time only by another hex
		eeprom_write(0x01,3);//burn this value in this location one time only by another hex
		power_cut();
	while (1)
	{
		//lcd admin pass
		if(counter==3){//change it number of digit password
			counter=0;
			if(enterd_pass==real_pass) 
			{
				lcd_clear_screen();LCD_WRITE_STRING("true");_delay_ms(1000);
			lcd_clear_screen();LCD_WRITE_STRING("enter new id");SET_CURSOR(1,0);
			uint8_t id_inc=0;uint32_t new_id=0;
			while(id_inc<=6)
			{
				char x=get_key();
				switch(x)
				{
					case 'N':break;
					default: {LCD_WRITE_CHAR(x);new_id=(x-48)+new_id*10;id_inc++;}
				}
			}
			ids[number_of_id++]=new_id;
			
			
			eeprom_send_7_bytes(new_id);
			lcd_clear_screen();
			LCD_WRITE_STRING("id ");lcd_write_num(new_id);SET_CURSOR(1,0);
			LCD_WRITE_STRING("is added");eeprom_write(0x00,number_of_id);
			cut_off+=1;////power cut simulation
				}
			else{lcd_clear_screen();LCD_WRITE_STRING("try again");}
			_delay_ms(1000);lcd_clear_screen();
			LCD_WRITE_STRING("enter pass::>> ");SET_CURSOR(1,0);enterd_pass=0;
		}
		
		char x=get_key();
		switch(x)
		{
			case 'N': break;
			default: {LCD_WRITE_CHAR('*');enterd_pass=(x-48)+enterd_pass*10;counter++;}
		}
		////////to not concatinate between two gates spi id you can send to another spi a busy state like delay function to not accept any id when another take id
		///spi
		uint8_t spi_master_rec=send_rec_data(0xff);
			if(spi_master_rec ==16)
			{car_state++;LCD_WRITE_STRING("busy");}
			else if(spi_master_rec ==17)
			{car_state+=2;LCD_WRITE_STRING("busy");}
			else if(spi_master_rec) 
			{
				if(spi_master_rec !=128)//128 for char send space???? ??? ???? ?????? 
				{
				//if(first_five !=0){///for simulation error
				enterd_id=enterd_id*10+(spi_master_rec-48);
				//LCD_WRITE_CHAR(spi_master_rec);/////////////////////////////////////////////////////////
				id_counter++;
				//}
				//first_five=1;
				}
			}
		
			if(id_counter ==7){
				flag=check_pass();
				
		if(flag==1 && car_state==1) {
			real_num_of_Cars--;
			if(real_num_of_Cars>=0 && real_num_of_Cars<=3){
			spi_send_data(10);}
			else {real_num_of_Cars=0;spi_send_data(12);}
			}
		else if(flag==0 && car_state==1) {spi_send_data(11);}
		else if(flag==1 && car_state==2) {
			real_num_of_Cars++;
			if(real_num_of_Cars<=3 && real_num_of_Cars>=0){
			spi_send_data(13);}
			else {real_num_of_Cars=3;spi_send_data(15);}//not important case 
		}
		else if(flag==0 && car_state==2) {spi_send_data(14);}
		
		
		enterd_id=0;car_state=0;flag=0;id_counter=0;
				//_delay_ms(1000);//you can delet delay now 
				lcd_clear_screen();LCD_WRITE_STRING("enter pass::>> ");SET_CURSOR(1,0);PORTD=real_num_of_Cars;eeprom_write(0x01,real_num_of_Cars);LCD_WRITE_CHAR(eeprom_read(0x01)+48);
				}
				
				
				
				if(cut_off==2)////power cut simulation
				{
					power_cut();
					cut_off=3;
				}
				
	}
	}
