import java.util.Calendar;

public class ThreadViderHistorique extends Thread{
    boolean condition=true;
    int jourReference =0;

    public ThreadViderHistorique()
    {
        Calendar calendar = Calendar.getInstance();
        jourReference = calendar.get(Calendar.DAY_OF_MONTH);
    }

    public void arret()
    {
        condition=false;
    }

    public void run()
	{
		do {
			try {
				Thread.sleep(6000);
			}catch(InterruptedException e )
			{
				e.printStackTrace();
			}
		//en reel
			/*Calendar calendar = Calendar.getInstance();
			int jour= calendar.get(Calendar.DAY_OF_MONTH);
			if(jour!=jourReference)
			{
				jourReference = jour;
				System.out.println("Vider commande");
			}*/
		//pour le test  
			BDHistorique bdHistorique = BDHistorique.getInstance();
			Calendar calendar = Calendar.getInstance();
			int minute= calendar.get(Calendar.MINUTE);
			if(minute==21)
			{
				bdHistorique.viderHistorique();
			}
			
			
		}while(condition);
	}
}
