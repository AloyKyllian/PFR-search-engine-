
public class ELLEMENT{

    public String ID;
    public String chemin;

    public ELLEMENT (String ID, String chemin)
    {
        this.ID=ID;
        this.chemin=chemin;
    }
    public String toString()
    {
        String text="";
        text="ID "+ID+" Chemin "+chemin;
        return text;
    }
}