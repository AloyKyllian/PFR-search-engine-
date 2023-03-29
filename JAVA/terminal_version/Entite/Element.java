package Entite;

public class Element {
    public String ID;
    public String chemin;

    public Element (String ID, String chemin)
    {
        this.ID=ID;
        this.chemin=chemin;
    }
    public String toString()
    {
        String text="";
        text="ID: "+ID+"\n Chemin: "+chemin;
        return text;
    }

}
