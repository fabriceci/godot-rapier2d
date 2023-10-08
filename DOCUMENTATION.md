# test_body_motion

## Step 1

We check if the body + margin collide something:
![Body Test Motion Step 1](docs/test_body_motion_step_1.png)
- if true: 
    
    we loop 4 times: 
        
        we depenetrate the body but not of the full penetration, 0,4 
- if false: go to step 2

## Step 2
                
We apply the motion to the body and build a aabb from the body start to the body end. 
We try the colliding distance (lower one). And we need two value: safe (when it does not collide), unsafe (where it collide)

## Step 3
            
- If collided:

    We put the body at the unsafe position to retrieve the collision info, we want the closer collision
- We send the info

