package myswing;

import javax.swing.*;
import java.awt.event.*;


public class MyFrame extends JFrame{
	
		JButton doIt, close;
		JLabel label = new JLabel();
		public static void main(String argv[ ]) {
			
			MyFrame mf = new MyFrame();
			
		}
		
		public MyFrame(){
			doIt.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					// TODO Auto-generated method stub
					
				}
			});
			
			close.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					// TODO Auto-generated method stub
					
				}
			});
			setDefaultCloseOperation(EXIT_ON_CLOSE);
			pack();
			setVisible(true);
		}
		
	
}
