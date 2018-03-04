public class Funciones {
    public static void main(String[] args) {
        if (args.length < 1){
            System.out.println("Olvidaste ingresar un valor");
            return;
        }
        double i = 1;
        double seno = 0;
        double coseno = 0;
        double tangente = 0;
        double logaritmo = 0;
        double raiz = 0;
        double max = Double.parseDouble(args[0]);

        long startTime = System.nanoTime();
        while(i<max) {
            seno += Math.sin(i);
            coseno += Math.cos(i);
            tangente += Math.tan(i);
            logaritmo += Math.log10(i);
            raiz += Math.sqrt(i);
            i++;
        }
        long stopTime = System.nanoTime();
        long elapsedTime = stopTime - startTime;
        double segundos = elapsedTime / 1000000000f;
        System.out.println("max: " + max + " tiempo: " + segundos + " s");
    }
}