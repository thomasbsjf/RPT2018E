package trb;

public class Sorts {
    private Integer contadorCompara, numRegistros;

    public Integer getContadorCompara() {
        return contadorCompara;
    }

    public void setContadorCompara() {
        this.contadorCompara = contadorCompara + 1;
    }

    public Integer getNumRegistros() {
        return numRegistros;
    }

    public void setNumRegistros() {
        this.numRegistros = numRegistros + 1;
    }
    
    public void merging(int vet[], int inicio, int meio, int fim)
    {

        Integer i, j, k;
        Integer[] aux = new Integer[vet.length];
        i = inicio;
        j = 1+meio;
        k = inicio;

        while(i <= meio && j <= fim)
        {
            if(vet[i]<= vet[j])
            {
                aux[k] = vet[i];
                i++;
            }
            else
            {
                aux[k] = vet[j];
                j++;
            }
            k++;
        }
        for(int q = i; q <=meio; ++q)
        {
            aux[k] = vet[q];
            k++;
        }


        for(int q = j; q<= fim; ++q)
        {
            aux[k] = vet[q];
            k++;
        }

        for(int q = inicio; q<= fim; ++q)
        {
            vet[q] = aux[q];
        }
    }

    public void mergeSort(int vet[], int inicio, int fim)
    {
        if(inicio < fim)
        {
            int meio = (inicio + fim)/2;
            mergeSort(vet,inicio,meio);
            mergeSort(vet,meio+1,fim);
            merging(vet, inicio, meio, fim);
        }
    }

    public void insertionSort(int vet[], int tam)
    {
           setContadorCompara();
           setNumRegistros();
           for(int i = 1; i< tam; i++)
           {
               int pivo = vet[i];
               setNumRegistros();
               int j = i - 1;
               setNumRegistros();
               while(j>=0 && vet[j] > pivo)
               {
                   setContadorCompara();
                   if(vet[j] > pivo)
                   {
                       setContadorCompara();
                       vet[j+1] = vet[j];
                       setNumRegistros();
                       j--;
                   }
               }
               vet[j+1] = pivo;
               setNumRegistros();
           }
       }

    public void constroiHeap(int vet[], int tam, int raiz)
    {
        int ram, valor; // ram = ramificação
        valor = vet[raiz];

        while(raiz < (tam/2))
        {
            ram = 2*raiz + 1;
            if(ram < tam -1 && vet[ram] < vet[ram +1])
            {
                ram++;
            }
            if(valor >= vet[ram])
            {
                break;
            }
            vet[raiz] = vet[ram];
            raiz = ram;
        }
        vet[raiz] = valor;
    }

    public void heapSort(int vet[], int tam) // FAZER!
    {
        //int troca;
        for(int i = tam/2; i>= 0; i--)
        {
            constroiHeap(vet,tam, i);
        }
        while(tam >0)
        {
            swap(vet[0],vet[tam-1]);
            constroiHeap(vet,--tam,0);
        }
    }

    public int quickSepara(int vet[], int inicio, int fim)
    {
        int esq, dir, aux, pivo;
        esq = inicio;
        setNumRegistros();
        dir = fim;
        setNumRegistros();
        pivo = vet[inicio];
        setNumRegistros();
        while(esq<dir)
        {
            setContadorCompara();
            while(vet[esq]<= pivo)
            {
                setContadorCompara();
                esq++;
                setNumRegistros();
            }
            while(vet[dir]> pivo)
            {
                setContadorCompara();
                dir--;
                setNumRegistros();
            }
            if(esq<dir)
            {
                setContadorCompara();
                aux = vet[esq];
                setNumRegistros();
                vet[esq] = vet[dir];
                setNumRegistros();
                vet[dir] = aux;
                setNumRegistros();
            }
        }
        vet[inicio] = vet[dir];
        setNumRegistros();
        vet[dir] = pivo;
        setNumRegistros();
        return dir;
    }

    public int quickSeparaMediana(int vet[], int inicio, int fim, int mediana)
    {
        int esq, dir, aux, pivo;
        esq = inicio;
        dir = fim;
        pivo = vet[mediana];
        while(esq<dir)
        {
            while(vet[esq]<= pivo)
            {
                esq++;
            }
            while(vet[dir]> pivo)
            {
                dir--;
            }
            if(esq<dir)
            {
                aux = vet[esq];
                vet[esq] = vet[dir];
                vet[dir] = aux;
            }
        }
        vet[inicio] = vet[dir];
        vet[dir] = pivo;
        return dir;
    }

    private void swap(int i, int i0) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public void quickSort(int vet[],int inicio, int fim)
    {
        if(inicio < fim)
        {
            int indicePivo = quickSepara(vet,inicio,fim);
            quickSort(vet,inicio,indicePivo);
            quickSort(vet,indicePivo+1,fim);
        }

    }

    public void quickSortInsertion(int vet[], int inicio, int fim)
    {
        int tamanho = fim-inicio;
        insertionSort(vet, tamanho);
    }

    public int medianaDeTres(int vet[],int inicio, int fim)
    {
        int meio = (fim-inicio)-1/2;

        if(vet[inicio] > vet[meio])
        {
            swap(inicio,meio);
        }
        if(vet[inicio] > vet[fim])
        {
            swap(inicio,fim);
        }
        if(vet[meio]> vet[fim])
        {
            swap(meio,fim);
        }
        swap(meio,fim);
        return fim;
    }

    public void quickSortMedianaTres(int vet[], int inicio, int fim)
    {
        if((fim - inicio) <= 3)
        {
            manualSortQuick(vet,inicio,fim);
        }
        else
        {
            Integer mediana = medianaDeTres(vet, inicio, fim);
            Integer indicePivo = quickSeparaMediana(vet, inicio, fim, mediana);
            quickSort(vet,inicio,indicePivo-1);
            quickSort(vet,indicePivo+1,fim);
        }
    }

    public void manualSortQuick(int vet[], int inicio, int fim)
    {
        int tam = (fim-inicio);

        if(tam == 2)
        {
            if(vet[inicio] > vet[fim])
                swap(inicio,fim);
        }
        else if(tam > 2)
        {
            int meio = fim-1;
            if(vet[inicio] > vet[meio])
                swap(inicio,meio);
            if(vet[inicio]> vet[fim])
                swap(inicio,fim);
            if(vet[meio]> vet[fim])
                swap(meio,fim);
        }
    }

   public void shellSort(int vet[], int tam)
   {
       int i , j , valor;
       int lacuna = 1;
       while(lacuna < tam) {
           lacuna = 3*lacuna+1;
       }
       while ( lacuna > 1) {
           lacuna /= 3;
           for(i = lacuna; i < tam; i++) {
               valor = vet[i];
               j = i;
               while (j >= lacuna && valor < vet[j - lacuna]) {
                   vet[j] = vet [j - lacuna];
                   j = j - lacuna;
               }
               vet [j] = valor;
           }
       }
   }
}