use std::ops::{Add, Div, Sub, Mul};
use std::fmt::Display;

pub trait CoefficienteMatrice: Add<Output = Self> + Div<Output = Self> + Mul<Output = Self> + Sub<Output = Self> + Display + Clone + Copy {
    fn new() -> Self; // serve per inizializzare la matrice, è comodo, inizializza ad 1;
    fn nullo(&self) -> bool; // ritorna true se vale 0, false altrimenti
    fn opposto(&mut self) -> Self; // moltiplica per -1
}

pub trait Matrice<E: CoefficienteMatrice>: Display + Clone {
    fn new(righe: usize, colonna: usize) -> Self; // la prende dal terminale
        //fn from_vector<T: Matrice>(vect: &T, righe: usize, colonne: usize) -> Box<Self>;
    fn colonne(&self) -> usize;
    fn righe(&self) -> usize;
    fn value(&self, index: usize) -> E; // ritorna il valore nella posizione index
    fn mut_value(&mut self, index: usize) -> &mut E;   // ritorna il valore nella posizione index, può essere modificato 
    fn len(&self) -> usize; // numero dei coefficienti della matrice righe * colonne
    fn estrai_riga(&mut self, index: usize) -> &mut [E];
//    fn estrai_colonna(&mut self, index: usize) -> Vec<&mut E>;

    fn nullo(&self, index: usize) -> bool { // true se il numero alla posizione index == 0
        self.value(index).nullo()
    }

    // scambia due righe di una matrice
    fn scambia_righe(&mut self, riga1: usize, riga2: usize) {
        let mut sup: E;
        for i in 0..self.colonne() {
            sup = self.value(riga1 * self.colonne() + i);
            *self.mut_value(riga1 * self.colonne() + i) = self.value(riga2 * self.colonne() + i);
            *self.mut_value(riga2 * self.colonne() + i) = sup;
        }
    }

    // trova il primo coefficiente della riga non nullo, 
    // lo divide per se stesso e divide per lo stesso valore 
    // i restati valori della riga indicata
    fn riga_dominante(&mut self, riga: usize) -> E {
        let mut i = 0;
        while self.nullo(riga + i) {    // controlla se il valore attuale è nullo
            // print!("{}\n", i);
            i += 1;
        }
        let sup = self.value(riga + i); // imposta per quale valore dividere il resto della riga
        while i < self.colonne() {
            *self.mut_value(riga + i) = self.value(riga + i) / sup;
            i += 1;
        }
        sup
    }

    // sottrae riga1 a riga2
    fn make_colonnadominante(&mut self, riga1: usize, riga2: usize) -> E {
    //    let mut i = riga +1;
    //    while i< self.righe() {
        let mut j = 0;
        while self.nullo(riga1 * j) {   // controlla se il valore attuale è nullo
            j+= 1;
        }
        let sup = self.value(riga2 + j);    // indica la costare da moltiplicare
        if self.nullo(riga2 + j) {  // se il valore è nullo allora si moltiplica per 0 ed è inutile
            return sup; // serve per risolvere i sistemi
        }
        while j< self.colonne() {   // è sottratto il sup per il coefficiente della riga superiore
            *self.mut_value(riga2 + j) = self.value(riga2 + j) - self.value(riga1 + j) * sup;
                j += 1;
        }
        sup
    }

//    type Val = <T as Matrice>::Cell;    // !! Da cambiare!!
    //type E= f32; // da cambiare

    // trova la colonna dominante e ritorna il suo indice
    fn dominante(&self, index: usize) -> Option<usize> {
        let mut j: usize= 0;
        while j<self.colonne() {
            let mut i: usize= index;
            while i<self.righe() {
                if !self.nullo(i*self.colonne() +j) { return Some(i);}
                i+= 1;
            }
            j+= 1;
        }
        None
    }

    // effettua l'eliminazione di gauss, ritorna None se non è fattibile (se non si tratta di una matrice)
    // altrimenti ritorna k| k * det(matrice_risultante) = det(matrice iniziale) (Calcolo del determinante con l'algoritmo di Gauss)
    fn elm_gauss(&mut self) -> Option<E> {
        if self.len() != self.righe() * self.colonne() { return None; }
        let mut i= 0;
        let mut k= E::new();
        while i<self.righe() {
            match self.dominante(i) {
                None => { return Some(k); }
                Some(x) => { 
                    if x>i {
                        self.scambia_righe(i, x);
                        k.opposto();
                    }
                }
            }
            k = k / self.riga_dominante(i * self.colonne());
            for j in i+1..self.righe() {
                self.make_colonnadominante(i * self.colonne(), j * self.colonne());
            }
    //      stampa_matrice(A, righe, colonne);
    //      printf("\n");
            i += 1;
        }
        Some(k)
    }

    // calcola il rango della matrice
    fn rango(&self) -> usize {
        let mut mat = self.clone();  // non cambia la matrice iniziale
        mat.elm_gauss();    // effettua l'eliminazione di gauss
        let mut j = 0;
        for i in 0..self.righe() {
            match mat.dominante(i) {
                None => { return j; }
                Some(x) => {
                    if x == i { 
                        j += 1;    // conta le colonne dominanti
                    }
                }
            }
        }
        j   // ritorna il numero di colonne dominanti
    }

    // considerando il rango di una matrice ne calcola il numero di soluzioni: la matrice deve essere già ridotta
    fn check_soluzioni(&self, b: &Self) -> Option<usize> {
        for i in 0..self.colonne() {
            match self.dominante(i) {
                None => {
                    if b.len() > i {
                        for j in i..b.len() {
                            if !b.nullo(j) { return None; }
                        }
                        return Some(self.colonne() - self.rango());
                    }
                }
                _ => {}
            }
        }
        Some(0)
    }

    // Operazioni con le matrici

    fn trova_incognite(&self, b: &mut Self) {
        let mut i: usize = self.righe() -1;
        loop {
            let mut j= self.colonne() -1;
            while j > i {
        //        printf("%.2f %.2f\n", A[i*colonne +j], B[j]); // fino a qui tutto bene
                *b.mut_value(i) = b.value(i) - b.value(j) * self.value(i * self.colonne() + j);
                j-= 1;
            }
            i = if i ==0 { break;} else {i-1}; 
        }
    }

    fn elm_gauss_per_sistema(&mut self, b: &mut Self) -> E {   //
        let mut i= 0;
        let mut k = E::new();
        while i< self.righe() {
            match self.dominante(i) {
                None => { return k; }
                Some(x) => { if x> i {
                    self.scambia_righe(i, x);
                    b.scambia_righe(i, x);
                    k.opposto();
                }}
            }
            let sup = self.riga_dominante(i * self.colonne());
            *b.mut_value(i) = b.value(i) / sup;
            k = k / sup;
            for j in i+1..self.righe() {
                let sup = self.make_colonnadominante(i * self.colonne(), j * self.colonne());
                *b.mut_value(j)= b.value(j) - b.value(i) * sup;
            }
            i += 1;
        }
        k
    }

    fn risolvi_sistema(&mut self, b: &mut Self) -> Option<usize> {
        if self.len() != self.righe() * self.colonne() || self.righe() != b.righe() { return None; }
        let mut mat =self.clone();
        mat.elm_gauss_per_sistema(b);
        // println!("{}\n{}", self, b); // so far funziona!
        if self.rango() < self.colonne() { return mat.check_soluzioni(b);}
        // println!("{}\n{}", self, b); // so far funziona! 
        else {
            mat.trova_incognite(b);
            Some(0)
        }
    }

    // calcolo del determinante con l'algoritmo di gauss
    fn determinante(&self) -> Option<E> {
        if self.colonne() != self.righe() { None }
        else {
            let mut mat = self.clone();
            let mut det = mat.elm_gauss()?;
            for i in 0..mat.colonne() {
                det = det * mat.value(i * self.colonne() + i);
            }
            Some(det)
        }
    }

    fn mol_mat(&self, a: &Self) -> Option<Self> {
        if self.colonne() != a.righe() {return None;}
        let mut mat = Self::new(self.righe(), a.colonne());
        for riga in 0..mat.righe() {
            for colonna in 0..mat.colonne() {
                *mat.mut_value(riga * mat.colonne() + colonna) = E::new() - E::new();
                for ptr in 0..self.colonne() {
                    *mat.mut_value(riga * mat.colonne() + colonna) = mat.value(riga * mat.colonne() + colonna) + self.value(riga * self.colonne() + ptr) * a.value(ptr * a.colonne() + colonna);
                }
            }
        }
        Some(mat)
    }
}

// 