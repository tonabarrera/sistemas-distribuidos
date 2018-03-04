class Cadenota {
    public static void main(String[] args) {
        if (args.length < 1){
            System.out.println("Olvidaste ingresar un valor");
            return;
        }
        int cantidad = 0;
        long numero = Long.parseLong(args[0]);
        StringBuilder cadenota = new StringBuilder();
        char[] letras = new char[4];
        letras[3] = ' ';
        int rango = (90 - 65) + 1;
        long startTime = System.nanoTime();
        for (long i = 0; i < numero ; i++) {
            letras[0] = (char)((Math.random()*rango) + 65);
            letras[1] = (char)((Math.random()*rango)+ 65);
            letras[2] = (char)((Math.random()*rango)+ 65);
            cadenota.append(letras);
        }
        int pos = 0;
        while ((pos = cadenota.indexOf("IPN", pos)) != -1){
            cantidad++;
            pos += 4;
        }
        long stopTime = System.nanoTime();
        long elapsedTime = stopTime - startTime;
        double segundos = elapsedTime / 1000000000f;
        System.out.println("tiempo: " + segundos + " s");
        System.out.println("N=" + numero + " Numero de IPN: " + cantidad);
    }
}