/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {

    return{
        toBe : (val2)=>{
            if(val2 === val){
                return true
            }else{
                throw new Error("Not Equal")
            }
        },

        notToBe : (val3)=>{
            if(val3 !== val){
                return true
            }else{
                throw new Error("Equal");
            }
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */