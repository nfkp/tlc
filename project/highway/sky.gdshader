shader_type sky;

vec2 mod289(const in vec2 x) { return x - floor(x * (1. / 289.)) * 289.; }
vec3 mod289(const in vec3 x) { return x - floor(x * (1. / 289.)) * 289.; }

vec3 permute(const in vec3 v) { return mod289(((v * 34.0) + 1.0) * v); }

float snoise(in vec2 v) {
    const vec4 C = vec4(0.211324865405187,
                        0.366025403784439,
                        -0.577350269189626,
                        0.024390243902439);

    vec2 i  = floor(v + dot(v, C.yy) );
    vec2 x0 = v -   i + dot(i, C.xx);

    vec2 i1;
    i1 = (x0.x > x0.y) ? vec2(1.0, 0.0) : vec2(0.0, 1.0);
    vec4 x12 = x0.xyxy + C.xxzz;
    x12.xy -= i1;

    i = mod289(i);
    vec3 p = permute( permute( i.y + vec3(0.0, i1.y, 1.0 ))
    + i.x + vec3(0.0, i1.x, 1.0 ));

    vec3 m = max(0.5 - vec3(dot(x0,x0), dot(x12.xy,x12.xy), dot(x12.zw,x12.zw)), 0.0);
    m = m*m ;
    m = m*m ;

    vec3 x = 2.0 * fract(p * C.www) - 1.0;
    vec3 h = abs(x) - 0.5;
    vec3 ox = floor(x + 0.5);
    vec3 a0 = x - ox;

    m *= 1.79284291400159 - 0.85373472095314 * ( a0*a0 + h*h );

    vec3 g;
    g.x  = a0.x  * x0.x  + h.x  * x0.y;
    g.yz = a0.yz * x12.xz + h.yz * x12.yw;
    return 130.0 * dot(m, g);
}

#define RANDOM_SCALE vec4(.1031, .1030, .0973, .1099)

float featherstep(float a, float b) {
    float v = (a - b) * 60. + 0.5;
    return smoothstep(1., 0., v);
}

float random(in vec2 st) {
    return fract(sin(dot(st.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

vec2 random2(vec2 p) {
    vec3 p3 = fract(p.xyx * RANDOM_SCALE.xyz);
    p3 += dot(p3, p3.yzx + 19.19);
    return fract((p3.xx + p3.yz) * p3.zy);
}

void sky() {
	vec2 st = EYEDIR.xy;
	vec3 color = vec3(0.);

    st.x -= 0.5;
    st.y *= sqrt(1. - pow(st.y, 2.));
    st.x *= 6.28318530718;

    st *= 15.;
    vec2 i = floor(st);
    vec2 f = fract(st);

    float d = (random(i) - 0.5) * 5.;
    vec2 r = (random2(i) - .5) * d;
    f -= .5;
    float pct = length(f + r);
    pct = featherstep(pct, d * 0.00625);
    pct += snoise(st) * 0.5 * 0.01;
	color = vec3(pct);
    color += mix(vec3(0.410,0.413,0.630), vec3(0.700,0.664,0.576), pow(clamp(1. - st.y * 0.7, 0., 1.), 2.)) * 0.6;

    COLOR =  color * clamp(sign(EYEDIR.y), 0., 1.);

	COLOR = pow(COLOR, vec3(2.2));
	COLOR += vec3(0.00223, 0.00244, 0.01066) * clamp(-sign(EYEDIR.y), 0., 1.);
}
