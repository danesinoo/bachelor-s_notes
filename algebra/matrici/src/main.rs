mod complesso;
mod matricecomplessa;
mod matricereale;
pub mod matrici;
use matricereale::MatriceReale;
use matrici::Matrice;

fn main() -> Result<(), &'static str> {
    let mut mat: Vec<f32> = vec![
        1., 1., -1., 1., 0., 0., 0., 1., -1., 1., 0., 1., 0., 0., 1., 1., -1., 0., 0., 1., 0., 1.,
        -1., 1., 0., 0., 1., 0.,
    ];

    let mut mat_reale = MatriceReale {
        matrice: mat,
        colonne: 7,
        righe: 4,
    };

    let mat1 = mat_reale.clone();

    mat_reale.elm_gauss();

    mat = vec![
        0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 1., 0., 0., 0., 0., 1., 0., 0., 0., 0., 1.,
        0., 0., 0., 0., 1.,
    ];

    let mat_id = MatriceReale {
        matrice: mat,
        colonne: 4,
        righe: 7,
    };

    mat = vec![
        1., 0., 0., 0., 1., 0., 0., 0., 1., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
    ];

    let mat_id2 = MatriceReale {
        matrice: mat,
        colonne: 3,
        righe: 7,
    };

    let h = mat_reale.mul(&mat_id).unwrap();
    let c = mat_reale.mul(&mat_id2).unwrap();
    let mat1 = mat1.mul(&mat_id2).unwrap();
    print!(
        "{}\n{}\n{}\n{}",
        mat1.table(),
        h.table(),
        c.table(),
        h.mul(&mat1).unwrap().table()
    );
    Ok(())
}
