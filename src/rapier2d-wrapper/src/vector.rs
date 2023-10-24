use rapier2d::prelude::*;

#[repr(C)]
pub struct Vector {
    pub x : Real,
    pub y : Real,
}

pub fn point_array_to_vec(data : &Vector, data_count : usize) -> Vec::<Point::<Real>> {
    let mut vec = Vec::<Point::<Real>>::with_capacity(data_count);
    unsafe {
        let data_raw = std::slice::from_raw_parts(data, data_count);
        for point in data_raw {
            vec.push(Point::<Real> { coords : vector![point.x, point.y] });
        }
    }
    return vec;
}
