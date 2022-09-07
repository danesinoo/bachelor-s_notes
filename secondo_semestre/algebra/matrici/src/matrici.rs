use std::ops::{Add, Div, Sub, Mul};
use std::fmt::Display;
use prettytable::{Table, Row, Cell};
use prettytable::format;

pub trait CoefficienteMatrice: Add<Output = Self> + Div<Output = Self> + Mul<Output = Self> + Sub<Output = Self> + Display + Clone + Copy {
    fn new() -> Self; // serve per inizializzare la matrice, è comodo, inizializza ad 1;
    fn nullo(&self) -> bool; // ritorna true se vale 0, false altrimenti
    fn opposto(&self) -> Self; // self * -1
}

pub trait Matrice<E: CoefficienteMatrice>: Clone {
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
        while self.nullo(riga1 + j) {   // controlla se il valore attuale è nullo
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
    fn dominante(&self, index: usize) -> Result<usize, &str> {
        let mut j: usize= 0;
        while j<self.colonne() {
            let mut i: usize= index;
            while i<self.righe() {
                if !self.nullo(i*self.colonne() +j) { return Ok(i);}
                i+= 1;
            }
            j+= 1;
        }
        Err("Non ci sono più righe non nulle")
    }

    // effettua l'eliminazione di gauss, ritorna None se non è fattibile (se non si tratta di una matrice)
    // altrimenti ritorna k| k * det(matrice_risultante) = det(matrice iniziale) (Calcolo del determinante con l'algoritmo di Gauss)
    fn elm_gauss(&mut self) -> Result<E, &str> {
        if self.len() == self.righe() * self.colonne() { 
            return Err("le righe e le colonne non combaciano con la dimensione della matrice"); 
        }
        let mut i= 0;
        let mut k= E::new();
        while i<self.righe() {
            match self.dominante(i) {
                Err(_) => { break }
                Ok(x) => { 
                    if x>i {
                        self.scambia_righe(i, x);
                        k = k.opposto();
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
       Ok(k)
    }

    // calcola il rango della matrice
    fn rango(&self) -> Result<usize, &str> {
        let mut mat = self.clone();  // non cambia la matrice iniziale
        match mat.elm_gauss() {
            Err(_) => {return Err("elm_gauss: le righe e le colonne non combaciano con la dimensione della matrice");},
            _ => {}
        }
            // effettua l'eliminazione di gauss
        let mut j = 0;
        for i in 0..self.righe() {
            match mat.dominante(i) {
                Err(_) => { break }
                Ok(x) => {
                    if x == i { 
                        j += 1;    // conta le colonne dominanti
                    }
                }
            }
        }
        Ok(j)   // ritorna il numero di colonne dominanti
    }

    // considerando il rango di una matrice ne calcola il numero di soluzioni: la matrice deve essere già ridotta
    fn check_soluzioni(&self, b: &Self) -> isize {
        for i in 0..self.colonne() {
            match self.dominante(i) {
                Err(_) => {
                    if b.len() > i {
                        for j in i..b.len() {
                            if !b.nullo(j) { return 0;}
                        }
                        return (self.colonne() as isize - self.rango().unwrap() as isize).abs();
                    }
                }
                _ => {}
            }
        }
        0        
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
                Err(_) => { return k; }
                Ok(x) => { if x> i {
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

    fn risolvi_sistema(&mut self, b: &mut Self) -> Result<isize, &str> {
        if self.len() != self.righe() * self.colonne() || self.righe() != b.righe() { 
            return Err("La matrice non ha le dimensioni adeguate, oppure il vettore dei termini noti non ha lo stesso numero di righe delle matrice"); 
        }
        let mut mat =self.clone();
        mat.elm_gauss_per_sistema(b);
        // println!("{}\n{}", self, b); // so far funziona!
        if self.rango()? < self.colonne() { return Ok(mat.check_soluzioni(b));}
        // println!("{}\n{}", self, b); // so far funziona! 
        else {
            mat.trova_incognite(b);
            Ok(0)
        }
    }

    // calcolo del determinante con l'algoritmo di gauss
    fn determinante(&self) -> Result<E, &str> {
        if self.colonne() != self.righe() { Err("La matrice non è quadrata") }
        else {
            let mut tmp = self.clone();
            let mut det = match tmp.elm_gauss() {
                Ok(x) => { x },
                Err(_) => { return Err("elm_gauss: le righe e le colonne non combaciano con la dimensione della matrice"); }
            };
            for i in 0..self.righe() {
                det = det * tmp.value(i * tmp.righe() + i);
            }
            Ok(det)
        }
    }

    fn mul(&self, a: &Self) -> Result<Self, &str> {
        if self.colonne() != a.righe() {
            return Err("Stai moltiplicando due matrici che hanno righe e colonne diverse, il codominio della seconda non coincide con il dominio della prima");
        }
        let mut tmp = Self::new(self.righe(), a.colonne());
        for riga in 0..tmp.righe() {
            for colonna in 0..tmp.colonne() {
                *tmp.mut_value(riga * tmp.colonne() + colonna) = E::new() - E::new();
                for ptr in 0..self.colonne() {
                    *tmp.mut_value(riga * tmp.colonne() + colonna) = tmp.value(riga * tmp.colonne() + colonna) + self.value(riga * self.colonne() + ptr) * a.value(ptr * a.colonne() + colonna);
                }
            }
        }
        Ok(tmp)
    }

    fn add(&self, rhs: &Self) -> Result<Self, &str> {
        if self.righe() != rhs.righe() || self.colonne() != rhs.colonne() {
            return Err("Sono sommate due matrici con dimensioni differenti");
        }
        let mut tmp= Self::new(self.righe(), self.colonne());
        for i in 0..self.righe() * self.colonne() {
            *tmp.mut_value(i) = self.value(i) + rhs.value(i);
        }
        Ok(tmp)
    }

    fn trasposta(&self) -> Self {
        let mut tmp = Self::new(self.colonne(), self.righe());
        for i in 0..self.righe() {
            for j in 0..self.colonne() {
                *tmp.mut_value(j * tmp.colonne() + i) = self.value(i * tmp.colonne() + j);
            }
        }
        tmp
    }

    fn table(&self) -> Table {
        let mut table = Table::new();
        let format = format::FormatBuilder::new()
            .borders('|')
            .separators(&[format::LinePosition::Top,
                        format::LinePosition::Bottom],
                        format::LineSeparator::new(' ', '+', '+', '+'))
            .padding(1, 5)
            .build();
        table.set_format(format);

        let mut row;
        for i in 0..self.righe() {
            row = Row::empty();
            for j in 0..self.colonne() {
                row.add_cell(Cell::new(&self.value(i * self.colonne() + j).to_string()));
            }
            table.add_row(row);
        }
        table
    }

    fn print(&self) {
        print!("{}", self.table())
    }
}
