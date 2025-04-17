package GUI;

import java.awt.FlowLayout;
import javax.swing.*;
import javax.swing.JRadioButton;

public class Rbat extends JFrame{
	
	Rbat(){
		   
		   JFrame f=new JFrame("ComboBox Example");
		   JRadioButton male = new JRadioButton("male");
		   JRadioButton female = new JRadioButton("Female");
		   JComboBox<JRadioButton> combo;
		   String country[]= {"India","Aus","USA","Turkey"};


		   ButtonGroup bG = new ButtonGroup();
		   f.add(male);
		   f.add(female);
		   f.setLayout( new FlowLayout());
		   f.add(male).setSize(50,100);;
		   f.add(female).setSize(50,100);;
		   male.setSelected(true);
		   f.setVisible(true);
		   
		   JComboBox cbz=new JComboBox(country);
		   cbz.setBounds(100, 100,90,20);
		   f.add(cbz);
		   f.setLayout(null);
		   f.setSize(400,500);
		   f.setVisible(true);
		   
		 }
}
