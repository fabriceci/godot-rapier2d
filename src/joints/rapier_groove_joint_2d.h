

class RapierGrooveJoint2D : public RapierJoint2D {
	union {
		struct {
			RapierBody2D *A;
			RapierBody2D *B;
		};

		RapierBody2D *_arr[2] = { nullptr, nullptr };
	};

public:
	virtual PhysicsServer2D::JointType get_type() const override { return PhysicsServer2D::JOINT_TYPE_GROOVE; }

	RapierGrooveJoint2D(const Vector2 &p_a_groove1, const Vector2 &p_a_groove2, const Vector2 &p_b_anchor, RapierBody2D *p_body_a, RapierBody2D *p_body_b);
};
